### 解题思路
执行用时 :
8 ms
, 在所有 C++ 提交中击败了
93.25%
的用户
内存消耗 :
17.5 MB
, 在所有 C++ 提交中击败了
5.11%
的用户
双指针，跳出条件是popped的数组全部被排除完毕

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len0 = pushed.size();
        int len1 = popped.size();
        int index0 = 0, index1 = 0;
        vector<int> result;
        while (index1 < len1) { // pushed >= popped
            if (index0 < len0) {
                result.push_back(pushed[index0]);
                if (pushed[index0] == popped[index1]) {
                    while (result.back() == popped[index1]) {
                        result.pop_back();
                        index1++;
                        if (index1 >= len1 || result.empty()) {
                            break;
                        }
                    }
                }
                index0++;
            } else { // pushed is all in
                if (result.back() == popped[index1]) {
                    result.pop_back();
                    index1++;
                } else {
                    break;
                }
            }
        }
        if (result.size() > 0) {
            return false;
        }
        return true;
    }
};
```