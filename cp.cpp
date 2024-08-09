#include <bits/stdc++.h>
#include <string>
using namespace std;

vector<int> starsRequired = {0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2};
void solve1()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int rank = 25;
        int stars = 0;
        int consecutiveWins = 0;

        for (char c : s)
        {
            if (c == 'W')
            {
                consecutiveWins++;
                stars++;
                if (rank >= 6 && rank <= 25 && consecutiveWins >= 3)
                {
                    stars++;
                }

                if (stars > starsRequired[rank])
                {
                    stars -= starsRequired[rank];
                    rank--;
                    if (rank == 0)
                    {
                        cout << "Archmage" << endl;
                        goto nextTestCase;
                    }
                }
            }
            else
            { // 'L'
                consecutiveWins = 0;
                if (rank <= 20)
                {
                    stars--;
                    if (stars < 0)
                    {
                        if (rank < 20)
                        {
                            rank++;
                            stars = starsRequired[rank] - 1;
                        }
                        else
                        {
                            stars = 0;
                        }
                    }
                }
            }
        }

        if (rank == 0)
        {
            cout << "Archmage" << endl;
        }
        else
        {
            cout << rank << endl;
        }

    nextTestCase:;
    }
}
void solve2()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> akshat(n);
    map<int, int> freq;

    for (int i = 0; i < n; ++i)
    {
        cin >> akshat[i];
        for (auto y = freq.begin(); y != freq.end(); ++y)
        {
            if (akshat[i] % y->first == 0 || y->first % akshat[i] == 0)
            {
                cnt += y->second;
            }
        }
        freq[akshat[i]]++;
    }
    cout << cnt << endl;
}
//question was removed
void solverem()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count[10] = {0};
        for (char c : s)
        {
            count[c - '0']++;
        }
        string filtered_s;
        for (char c : s)
        {
            if (count[c - '0'] % 2 != 0)
            {
                filtered_s.push_back(c);
            }
        }
        if (filtered_s.size() == 1)
        {
            cout << 0 << endl;
            continue;
        }
        sort(filtered_s.begin(), filtered_s.end());
        int min_diff = numeric_limits<int>::max();
        do
        {
            string s1 = filtered_s.substr(0, filtered_s.length() / 2);
            string s2 = filtered_s.substr(filtered_s.length() / 2);
            int num1 = stoi(s1);
            int num2 = stoi(s2);
            int diff = abs(num1 - num2);
            if (diff < min_diff)
            {
                min_diff = diff;
            }
        } while (next_permutation(filtered_s.begin(), filtered_s.end()));
        cout << min_diff << endl;
    }
}

void solve4()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int x = 1;
        int y = n;
        for (int i = 0; i < n; i += 2)
        {
            a[i] = x++;
            a[i + 1] = y--;
        }
        cout << n << endl;
        int f = n - 1;
        for (int i = 0; i < ceil((double)(n) / 2); i++)
        {
            int su = 0, du = 0;

            for (int j = 0; j < n - 2; j++)
            {
                su += abs(a[j + 1] - a[j]);
            }
            cout << su + max(abs(a[n - 2] - a[n - 1]), abs(a[n - 1] - a[0])) << " ";
            if (f != 0)
                cout << f << " ";
            f -= 2;
            for (int j = 0; j < n; j++)
            {
                a[j] = max(a[j] - 2, 0);
            }
        }
        cout << endl;
    }
}
void solve41()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        int x = 2;
        int y = n - 1;
        a[0] = (pow(n, 2) / 2) - 1;
        cout << n << endl;
        for (int i = 2; i < n; i += 2)
        {
            a[i] = a[i - 2] - x;
            x += 8;
            a[i - 1] = y;
            y -= 2;
        }
        if (n % 2 == 0)
        {
            a[n - 1] = 1;
            for (int i = n - 2; i > n / 2; i -= 2)
            {
                a[i] = a[i - 1] * (a[i - 1] - 1);
            }
        }
        else
        {
            for (int i = n - 1; i > n / 2; i -= 2)
            {
                a[i] = a[i - 1] * (a[i - 1] - 1);
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}

int countSubarrays(vector<int> arr, int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum <= k)
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}

void solve5()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (long long i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        long long result = 0;
        for (long long start = 0; start < n; ++start)
        {
            long long operations = 0;
            int ma = a[start];
            for (long long end = start; end < n; ++end)
            {
                if (end > start && a[end] < ma)
                {
                    operations += ma - a[end];
                }
                else if (end > start && a[end] > ma)
                {
                    ma = a[end];
                }
                if (operations <= m)
                {
                    result++;
                }
                else
                {
                    break;
                }
            }
        }

        cout << result << endl;
    }
}
void solve6()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> P(N), Q(N);

        for (int i = 0; i < N; i++)
        {
            cin >> P[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> Q[i];
        }

        // Check if we can rearrange P such that no two consecutive e are the same
        unordered_map<int, int> countP;
        int cnt = 0;
        for (int p : P)
        {
            countP[p]++;
            cnt = max(cnt, countP[p]);
        }

        if (cnt > (N + 1) / 2)
        {
            cout << "NO" << endl;
            continue;
        }

        // Sort P and Q
        sort(P.begin(), P.end());
        sort(Q.begin(), Q.end());

        bool possible = true;
        for (int i = 0; i < N; i++)
        {
            if (P[i] > Q[i])
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
void codef()
{

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> e;
        e.push_back(n);

        int s = 0;
        while (e.size() < n)
        {
            int c = e.back();
            e.pop_back();

            int sp;
            sp = k > c ? c - 1 : k - 1;
            for (int i = 0; i < sp; ++i)
                e.push_back(1);
            e.push_back(c - sp - 5 - 10 + 15);
            s = max(s, s + 1);
        }

        cout << s << endl;
    }
}
void codef22()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> sequence;
        long long current = 0;

        while (current <= n)
        {
            sequence.push_back(current + 1);
            current |= (current + 1);
        }

        cout << sequence.size() << endl;
        for (auto num : sequence)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// void solvear() {
//     int n, k;
//     cin >> n >> k;

//     int totalTools = n * k;
//     vector<int> tools(totalTools);
//     for (int i = 0; i < totalTools; ++i)
//         cin >> tools[i];

//     vector<int> favorite(n);
//     for (int i = 0; i < n; ++i)
//         cin >> favorite[i];

//     vector<int> satisfaction(k);
//     for (int i = 0; i < k; ++i)
//         cin >> satisfaction[i];

//     // Count frequency of each tool
//     map<int, int> freq;
//     for (int tool : tools)
//         freq[tool]++;

//     // Count number of favorite tools each artisan wants
//     map<int, int> wants;
//     for (int x : favorite)
//         wants[x] = k; // Each artisan wants exactly k tools of their favorite number

//     long long totalSatisfaction = 0;

//     // Calculate satisfaction
//     for (auto it = wants.begin(); it != wants.end(); ++it) {
//         int favNum = it->first;
//         int neededCount = it->second;

//         if (freq.count(favNum)) {
//             int availableCount = freq[favNum];

//             // Distribute tools for this artisan
//             while (neededCount > 0 && availableCount >0) {
//                 int maxPossible = min(availableCount / neededCount,k); // Maximum number of full sets of k tools
//                 totalSatisfaction += satisfaction[maxPossible - 1]; // Add satisfaction for this number of tools
//                 availableCount -= maxPossible; // Reduce available count of tools
//                 neededCount --; // Reduce needed count for this artisan
//             }
//         }
//     }

//     cout << totalSatisfaction << endl;
// }
void solvear()
{
    int n, k;
    cin >> n >> k;
    map<int, int> freq;
    int totalTools = n * k;
    vector<int> tools(totalTools);
    for (int i = 0; i < totalTools; ++i)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    map<int, int> wants;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        wants[x]++;
    }
    vector<int> satisfaction(k);
    for (int i = 0; i < k; ++i)
        cin >> satisfaction[i];

    long long totalSatisfaction = 0;

    // Calculate satisfaction
    for (auto it = wants.begin(); it != wants.end(); ++it)
    {
        int favNum = it->first;
        int neededCount = it->second;

        if (freq.count(favNum))
        {
            int availableCount = freq[favNum];

            // Distribute tools for this artisan
            while (neededCount > 0 && availableCount > 0)
            {
                int maxPossible = min(availableCount / neededCount, k);
                totalSatisfaction += satisfaction[maxPossible - 1];
                availableCount -= maxPossible;
                neededCount--;
            }
        }
    }

    cout << totalSatisfaction << endl;
}
const int MOD = 1000000007;

void graph()
{
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector<int> current_counts(n + 1, 0);
    vector<int> next_counts(n + 1, 0);
    current_counts[a] = 1;
    for (int step = 0; step < k; ++step)
    {
        fill(next_counts.begin(), next_counts.end(), 0);

        for (int i = 1; i <= n; ++i)
        {
            if (current_counts[i] > 0)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (j == i || j == b)
                        continue;
                    if (abs(j - i) < abs(b - i))
                    {
                        next_counts[j] = (next_counts[j] + current_counts[i]) % MOD;
                    }
                }
            }
        }
        current_counts = next_counts;
    }
    int total_sequences = 0;
    for (int i = 1; i <= n; ++i)
    {
        total_sequences = (total_sequences + current_counts[i]) % MOD;
    }
    cout << total_sequences << endl;
}
void cheff()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i <= n - k)
            {
                cnt -= (1 << i);
            }
            else
            {
                cnt += (1 << i);
            }
        }
        cout << cnt << endl;
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void cheff2()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        string S, T;
        cin >> S >> T;

        vector<int> freqS(2, 0), freqT(2, 0);
        bool f = false;
        for (char c : S)
        {
            freqS[c - '0']++;
            if (freqS[c - '0'] == 2)
                f = true;
        }
        for (char c : T)
            freqT[c - '0']++;
        if (S == T)
        {
            if (K % 2 == 0 || f)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }
        if (freqS != freqT)
        {
            cout << "NO" << endl;
            continue;
        }

        vector<int> mismatch_positions;
        for (int i = 0; i < N; ++i)
        {
            if (S[i] != T[i])
            {
                mismatch_positions.push_back(i);
            }
        }

        if (mismatch_positions.size() % 2 == 1)
        {
            cout << "NO" << endl;
        }
        else if (mismatch_positions.size() / 2 <= K && f)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> readMatrix(int n, int m)
{
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

bool isSingleElementMatrix(int n, int m)
{
    return (n == 1 && m == 1);
}

vector<vector<int>> generateShiftedMatrix(const vector<vector<int>> &a, int n, int m)
{
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int new_i = (i + (j == m - 1)) % n;
            int new_j = (j + 1) % m;
            b[new_i][new_j] = a[i][j];
        }
    }
    return b;
}

void outputMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}

void solveTestCase()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a = readMatrix(n, m);

    if (isSingleElementMatrix(n, m))
    {
        cout << -1 << endl;
    }
    else
    {
        vector<vector<int>> b = generateShiftedMatrix(a, n, m);
        outputMatrix(b);
    }
}

void solvexx()
{
    int t;
    cin >> t;
    while (t--)
    {
        solveTestCase();
    }
}

bool canTransform(const string &s, const string &t)
{
    int countS = 0, countT = 0;
    for (char c : s)
    {
        if (c == '1')
            countS++;
    }
    for (char c : t)
    {
        if (c == '1')
            countT++;
    }
    return countS == countT;
}

void solvexy()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        if (canTransform(s, t))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

#define int long long

void random1()
{
    int random1, random2;
    cin >> random1 >> random2;
    int random3[random1], random4[random1 + 1] = {0}, random5[random1 + 3] = {0};
    for (int i = 0; i < random1; ++i)
    {
        cin >> random3[i];
        random4[i + 1] = random4[i] + random3[i];
    }
    int random6 = 0;
    for (int i = random1 - 1; i >= 0; --i)
    {
        int random7 = random4[i] + random2;
        auto random8 = lower_bound(random4, random4 + random1 + 1, random7) - random4;
        if (random8 == random1 + 1)
            random5[i] += (random1 - i);
        else if (random7 == random4[random8])
            random5[i] += (random8 - i) + random5[random8 + 1];
        else
            random5[i] += (random8 - i - 1) + random5[random8];
    }
    for (int i = 0; i < random1 + 3; ++i)
    {
        random6 += random5[i];
    }
    cout << random6 << endl;
}

void random2()
{
    int random9 = 1;
    cin >> random9;
    while (random9--)
    {
        random1();
    }
}

void solveacm()
{
    int n;
    cin >> n;
    vector<int> cards(n), sumarr(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> cards[i];
    }
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += cards[i];
        sumarr[i] = sum;
    }
    stack<int> unlockedCards;
    int totalPoints = 0;
    int unlockedCount = 0;
    int i = n - 1, last = n;
skip:;
    if (sumarr[i] - sumarr[last] < sumarr[i - sumarr[i] - sumarr[last] < 0 ? 0 : i - sumarr[i] - sumarr[last]] - sumarr[i - 1])
    {
        last = i;
        i = i - sumarr[i] - sumarr[last];
        goto skip;
    }
    else
    {
        totalPoints = sumarr[i] - sumarr[last];
    }

    // Output the result
    cout << totalPoints << endl;
}

void solveaacm()
{
    long long n;
    cin >> n;
    vector<long long> cards(n);

    for (long long i = 0; i < n; ++i)
    {
        cin >> cards[i];
    }

    vector<long long> prefixSum(n + 1, 0);
    for (long long i = 1; i <= n; ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + cards[i - 1];
    }

    long long totalPoints = 0;
    vector<long long> unlocked;
    unlocked.push_back(cards[0]);

    for (long long i = 1; i < n;)
    {
        // Sort `unlocked` vector
        sort(unlocked.begin(), unlocked.end());

        // Find the index where the card value is valid
        int inx = -1;
        for (int j = 0; j < unlocked.size(); ++j)
        {
            if (unlocked[j] < (prefixSum[min(i + unlocked[j], n)] - prefixSum[i]) && unlocked[j] < n - i + 1)
            {
                inx = j;
            }
        }

        if (inx != -1)
        {
            // Add new cards to `unlocked`
            for (int j = i; j < i + unlocked[inx] && j < n; ++j)
            {
                unlocked.push_back(cards[j]);
            }
            // Move index forward
            i = min(i + unlocked[inx], n);
            unlocked.erase(unlocked.begin() + inx);
        }
        else
            break;
    }

    // Calculate total points
    for (long long xm : unlocked)
    {
        totalPoints += xm;
    }

    cout << totalPoints << endl;
}
void solveshelf()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = 1;
    }

    for (int start = 2; start <= n; ++start)
    {
        for (int i = 0; i <= n - start; ++i)
        {
            int j = i + start - 1;
            if (str[i] == str[j])
            {
                dp[i][j] = dp[i][j - 1];
            }
            for (int k = i; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;
}

void solvenecklace()
{
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    vector<string> results;

    for (int i = 0; i < m + k; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r, c;
            cin >> l >> r >> c;
            l--;
            r--;
            for (int j = l; j <= r; ++j)
            {
                s[j] = c + '0';
            }
        }
        else if (type == 3)
        {
            int l, r, shift;
            cin >> l >> r >> shift;
            l--;
            r--;
            int len = r - l + 1;
            shift %= len;
            if (shift != 0)
            {
                string temp = s.substr(l, len);
                for (int j = 0; j < len; ++j)
                {
                    s[l + j] = temp[(j + len - shift) % len];
                }
            }
        }
        else if (type == 2)
        {
            int l, r, d;
            cin >> l >> r >> d;
            l--;
            r--;
            bool passesCheck = true;
            for (int j = l; j <= r - d; ++j)
            {
                if (s[j] != s[j + d])
                {
                    passesCheck = false;
                    break;
                }
            }
            if (passesCheck)
            {
                results.push_back("PASS");
            }
            else
            {
                results.push_back("FAIL");
            }
        }
        else if (type == 4)
        {
            int l, r, t;
            cin >> l >> r >> t;
            l--;
            r--;
            bool passesCheck = true;
            for (int j = l + t; j <= r; ++j)
            {
                if (s[j] != s[j - t])
                {
                    passesCheck = false;
                    break;
                }
            }
            if (passesCheck)
            {
                results.push_back("PASS");
            }
            else
            {
                results.push_back("FAIL");
            }
        }
    }

    for (const string &result : results)
    {
        cout << result << endl;
    }
}
// void solveperm(){
//     int m;
//     cin >> m;
//     vector<int> y(m);
//     for (int i = 0; i < m; ++i) {
//         cin >> y[i];
//     }

//     int q;
//     cin >> q;
//     vector<pair<int, int>> queries(q);
//     for (int i = 0; i < q; ++i) {
//         cin >> queries[i].first >> queries[i].second;
//         queries[i].first--;
//         queries[i].second--;
//     }
//     for (const auto& query : queries) {
//         unordered_map<int, int> akshat;
//         for (int i = query.first; i <= query.second; ++i) {
//             freq[y[i]]++;
//         }

//         cout << akshat.size() << endl;
//     }
// }

void solvetechno()
{
    long long ts, gs, tt;
    cin >> ts >> gs >> tt;

    vector<long long> a(ts);
    for (long long i = 0; i < ts; ++i)
    {
        cin >> a[i];
    }

    vector<long long> q;
    q.reserve(ts * tt);
    for (long long i = 0; i < tt; ++i)
    {
        q.insert(q.end(), a.begin(), a.end());
    }

    bool modified = true;
    while (modified)
    {
        modified = false;
        vector<long long> new_q;
        new_q.reserve(q.size());

        long long i = 0;
        while (i < q.size())
        {
            long long start = i;
            while (i < q.size() && q[i] == q[start])
            {
                ++i;
            }
            long long length = i - start;
            if (length >= gs)
            {
                long long remainder = length % gs;
                if (remainder > 0)
                {
                    new_q.insert(new_q.end(), q.begin() + start, q.begin() + start + remainder);
                }
                modified = true;
            }
            else
            {
                new_q.insert(new_q.end(), q.begin() + start, q.begin() + i);
            }
        }

        q.swap(new_q);
    }

    cout << q.size() << endl;
}
// void solvecount()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, a, b;
//         cin >> n >> a >> b;
//         string s;
//         cin >> s;

//         int zc = 0, oc = 0;
//         unordered_map<pair<int, int>,int> aks;
//         aks[{0,0}] = 1;

//         int cnt = 0;

//         for (int i = 0; i < n; ++i)
//         {
//             if (s[i] == '0')
//                 zc++;
//             else
//                 oc++;

//             for (int j = 0; j <= oc; ++j)
//             {
//                 for (int k = 0; k <= zc + ((double(a) / b) * (j - oc)); k++)
//                 {
//                     if (aks[{k, j}]==1)
//                         cnt++;
//                 }
//             }
//             aks[{zc,oc}]=1;
//         }

//         cout << cnt << endl;
//     }
// }

void solvecount()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;

        int zc = 0, oc = 0;
        map<pair<int, int>, int> aks;
        aks[{0, 0}] = 1;

        int cnt = 0;
        double ratio = double(a) / b;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
                zc++;
            else
                oc++;

            auto it = aks.begin();
            while (it != aks.end())
            {
                pair<int, int> p = it->first;
                if (((double(zc) - p.first) / (oc - p.second)) >= double(ratio))
                {
                    cnt++;
                    ++it;
                }
            }
            aks[{zc, oc}] = 1;
        }

        cout << cnt << endl;
    }
}
// void solvebrush()
// {
//     int L;
//     cin >> L;
//     vector<int> heights(L);
//     for (int i = 0; i < L; ++i)
//     {
//         cin >> heights[i];
//     }

//     function<int(int, int)> minStrokes = [&](int left, int right)
//     {
//         if (left > right)
//             return 0;

//         int minHeight = *min_element(heights.begin() + left, heights.begin() + right + 1);
//         int strokes = minHeight;

//         for (int i = left; i <= right; ++i)
//         {
//             heights[i] -= minHeight;
//         }

//         int start = left;
//         while (start <= right)
//         {
//             while (start <= right && heights[start] == 0)
//                 ++start;
//             if (start > right)
//                 break;
//             int end = start;
//             while (end <= right && heights[end] > 0)
//                 ++end;
//             strokes += minStrokes(start, end - 1);
//             start = end;
//         }

//         return min(strokes, right - left + 1);
//     };

//     int result = minStrokes(0, L - 1);
//     cout << result << endl;
// }
void solveeldoria()
{
    int n;
    cin >> n;
    vector<int> g(n, -1);
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 1; i <= n; i++)
    {
        int m, nn;
        cin >> m >> nn;
        if (nn == 0)
        {
            // grid[i - 1][m - 1] = 1;
            grid[m - 1][i - 1] = 1;
        }
        else
        {
            if (nn != -1)
                g[i - 1] = m;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1)
        {
            if (grid[x][y] == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else if (type == 2)
        {
            if (grid[x - 1][y - 1])
            {
                cout << "NO\n";
                continue;
            }
            queue<int> qe;
            qe.push(y);
            bool f = false;
            while (!qe.empty())
            {
                int cur = qe.front();
                if (cur == x)
                {
                    cout << "YES\n";
                    break;
                    f = 1;
                }

                qe.pop();
                qe.push(g[cur - 1]);
                for (int x = 0; x < n; x++)
                {
                    if (grid[g[cur - 1]][x] == 1)
                        qe.push(x + 1);
                }
            }
            if (!f)
                cout << "NO\n";
        }
    }
}
void offline1()
{
    int t;
    cin >> t;
    while (t--)
    {
    }
}
void cc()
{
    string s = "akshaT";
    string c = s;
    reverse(c.begin(), c.end());
    cout << s << " " << *(s.end() - 1);
}
int32_t main(){solve1();return 0;}