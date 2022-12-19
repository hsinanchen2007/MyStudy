set存储，由于是(n+1)个不同元素，所以只要重复就一定是重复n次

代码：
```
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> s;
        int size = A.size();
        int ans;
        for (int i = 0; i < A.size(); i++) {
            if(s.find(A[i]) != s.end()) {
                ans = A[i];
                break;
            }
            else
                s.insert(A[i]);
        }
        return ans;
    }
};
```
