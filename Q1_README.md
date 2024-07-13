# Google-OA-Questions
## First Subsequence
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





