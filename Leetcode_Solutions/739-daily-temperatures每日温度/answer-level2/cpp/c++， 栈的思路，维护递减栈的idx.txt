### 解题思路
维护一个温度递减的idx栈，如果当前遇到的温度大于递减栈

则将所有小于当前温度的idx pop出去并计算当前栈顶的rst

### 代码

```cpp
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector <int> rst(T.size(), 0);
    vector <int> idx_stack;
    for (int i=0; i<T.size(); i++){
      if (idx_stack.empty() || T[i] <= T[idx_stack.back()]){
        idx_stack.push_back(i);
      } else {
        while (!idx_stack.empty() && T[i] > T[idx_stack.back()]){
          rst[idx_stack.back()] = i - idx_stack.back();
          idx_stack.pop_back();
        }
        idx_stack.push_back(i);
      }
    }

    return rst;
  }
};
```