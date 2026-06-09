### 解题思路
滑动窗口

### 代码

```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        
        int N = A.size();
        int ans = INT_MAX;
        vector<int> p(N+1);
        deque<int> d;
        for(int i=0;i<N;i++){
            p[i+1] = p[i] + A[i];
        }

        for(int j=0;j<p.size();j++){
            while(!d.empty() && (p[j]<=p[d.back()])){
                d.pop_back();
            }
            //cout << p[j] << endl;
            while(!d.empty() && (p[j]>=(p[d.front()] + K))){
                ans = min(ans,j-d.front());
                d.pop_front();
            }
            //cout << ans << endl;
            d.push_back(j);
        }

        return ans <= N ? ans : -1;
    }
};
```