### 解题思路
C++ + stack

### 代码

```cpp
const static int x = [](){ 
  ios::sync_with_stdio(false); 
  cin.tie(NULL); 
  // cout.tie(NULL); 
  return 0;  
}();
class Solution {
public:
    vector<int> maxDepthAfterSplit(const string& seq) {
        stack<int> s;
        int len = seq.size();
        vector<int> res(len, -1);
        int depth1 = 0;
        int depth2 = 0;
        for (int i = 0; i < len; ++i) {
            char c = seq[i];
            if(c == '(') {
                s.push(i);
                if (depth1 > depth2) {
                    res[i] = 1;
                    depth2++;
                } else {
                    res[i] = 0;
                    depth1++;
                }
            } else {
                int left = s.top();
                s.pop();
                res[i] = res[left];
                res[i] == 1 ? --depth2 : --depth1;
            }
        }
        return res;
    }
};
```