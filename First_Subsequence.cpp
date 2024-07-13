#include <iostream>
#include <string>
using namespace std;

bool isMatch(string &A, string &B, int st, int n, int m) 
{
    int j = 0;       // Start comparing from the first character of B
    int changes = 0; // Track the number of changes made
    for (int i = st; i < n && j < m; ++i) {
        if (A[i] == B[j]) {
            j++;
        }
        else if (changes == 0){
            changes++;
            j++;
        }
    }
    return (j == m) || (j == m - 1 && changes == 0);
}

int firstOccurrence(string &A, string &B) {
    int m = B.length();
    int n = A.length();
    for (int i = 0; i <= n - m; ++i)
    {
        if (A[i] == B[0] && isMatch(A, B, i, n, m))
        {
            return i + 1; // Convert to 1-based index
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(); // Consume newline

    while (T--)
    {
        string A, B;
        getline(cin, A);
        getline(cin, B);
        cout << firstOccurrence(A, B) << endl;
    }

    return 0;
}
