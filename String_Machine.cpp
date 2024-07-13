#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool lcs(const string &text1, const string &text2)
{
    int m = text1.size(), n = text2.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                curr[j] = next[j - 1] + 1;
            }
            else
            {
                curr[j] = max(next[j], curr[j - 1]);
            }
        }
        next = curr;
    }
    return curr[n] == n;
}

int solve(int n, const string &s1, int m, const string &s2, const vector<int> &p)
{
    int time = 1;
    string pat(s2.length(), '*');
    for (int i = 0; i < p.size(); ++i)
    {
        pat[p[i] - 1] = s2[p[i] - 1];
        if (lcs(pat, s1))
        {
            return time;
        }
        else
        {
            ++time;
        }
    }
    return -1;
}

// bool lcs(const string &text1, const string &text2){
//     int m = text1.length(), n = text2.length();
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
//     for (int i = 1; i <= m; ++i)
//     {
//         for (int j = 1; j <= n; ++j)
//         {
//             if (text1[i - 1] == text2[j - 1])
//             {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             }
//             else
//             {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }
//     return dp[m][n] == text2.length();
// }

int main()
{
    int n = 5;
    string s1 = "abc";
    int m = 6;
    string s2 = "aebdcf";
    vector<int> p = {1, 2, 3, 4, 5, 6};

    int result = solve(n, s1, m, s2, p);
    cout << "Result: " << result << endl;

    return 0;
}
