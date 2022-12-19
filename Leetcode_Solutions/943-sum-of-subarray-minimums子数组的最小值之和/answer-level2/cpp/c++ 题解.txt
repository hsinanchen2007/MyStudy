
贡献一份C++ AC代码
```
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <stack>

using namespace std;



class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int *left = new int [A.size()];
        int *right = new int [A.size()];
        stack<int> S;
        while (!S.empty()) S.pop();
        for (int i = 0; i < A.size(); ++i) {
            // if (S.empty() || A[i] > A[S.top()]) {
            //     S.push(i);
            //     left[i] = S.top() + 1;
            // }
            while (!S.empty() && A[i] <= A[S.top()]) {
                right[S.top()] = i-1;
                S.pop();
            }
            if (S.empty()) {
                S.push(i);
                left[i] = 0;
            }
            else {
                left[i] = S.top() + 1;
                S.push(i);
            }
        }
        while (!S.empty()) {
            right[S.top()] = A.size() - 1;
            S.pop();
        }
        long long ans = 0;
        int l;
        int r;
        int n;
        for (int i = 0; i < A.size(); ++i) {
            
            n = (right[i] - left[i] + 1);
            l = i - left[i];
            r = right[i] - i;
            // cout << n << endl;
            ans += (n + l * r) * A[i];
            ans %= (1000000000l + 7);
        }
        return ans;
    }
};
```