# Google-OA-Questions
## Q1) First Subsequence
![1](https://github.com/user-attachments/assets/597cb80f-6b1b-4a87-8137-3372e9db4247)
![2](https://github.com/user-attachments/assets/eaa8415e-551a-4c13-9c80-61fd44b0920b)
![3](https://github.com/user-attachments/assets/874b02a4-280a-4385-bba1-09f57ba02651)
![4](https://github.com/user-attachments/assets/f465e68e-de66-4dc8-9835-2bfd302f1187)
![5](https://github.com/user-attachments/assets/a3e77fb5-fe4e-4bd8-9515-19812f4eac35)
![6](https://github.com/user-attachments/assets/b6a578db-5010-4bc3-9ab6-1f12cb94428b)
```
bool isMatch(string &A, string &B, int st, int n, int m)
{
    int changes = 0, j = 0;
    for (int i = st; i < n && j < m; ++i)
    {
        if (A[i] == B[j]) {
            j++;
        }
        else if (changes == 0) {
            changes++;
            j++;
        }
    }
    return (j == m) || (j == m - 1 && changes == 0);
}

int firstOccurrence(string &A, string &B)
{
    int n = A.size(),  m = B.size();
    for (int i = 0; i <= n - m; ++i) {
        if (A[i] == B[0] && isMatch(A, B, i, n, m)) {
            return i + 1;
        }
    }
    return -1;
}
```
## Q2) String Machine 
![1](https://github.com/user-attachments/assets/dfeacc2c-eff0-4bb1-a5ee-f1e48d30d2aa)
![2](https://github.com/user-attachments/assets/68ec7a42-c92d-4767-bd4c-5968f51b9413)
![3](https://github.com/user-attachments/assets/6dc862bb-c279-46d5-b7e3-53936e4bf641)
![4](https://github.com/user-attachments/assets/ac390e06-6ab5-4dbf-bbb5-da27095bc21d)
![5](https://github.com/user-attachments/assets/cb798cdf-f157-4472-bda9-89e335ee421e)
![6](https://github.com/user-attachments/assets/9da65ea2-de1c-4271-b5e7-043a7514bb9a)

```

bool lcs(const string &text1, const string &text2){
    int m = text1.size(), n = text2.size();
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                curr[j] = next[j - 1] + 1;
            }
            else {
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
    for (int i = 0; i < p.size(); ++i) {
        pat[p[i] - 1] = s2[p[i] - 1];
        if (lcs(pat, s1)){
            return time;
        }
        else{
            ++time;
        }
    }
    return -1;
}
```


