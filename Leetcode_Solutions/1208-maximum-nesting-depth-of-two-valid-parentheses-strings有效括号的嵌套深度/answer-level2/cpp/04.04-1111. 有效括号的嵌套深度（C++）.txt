### 解题思路
最大深度的一半就够了

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<int> stack;
        int length = seq.length();
        int maxDepth = 0;
        vector<int> res(length,0);
        for (int i = 0; i < length; i++) {
            if (seq[i] == '(') {
                
                res[i] = stack.size();
                stack.push(i);
                maxDepth = max(maxDepth,res[i]);
            } else {
                res[i] = res[stack.top()];
                stack.pop();
            }
        }
        int minRes = (maxDepth + 1) / 2;
        for (int i = 0; i < length ; i++) {
            if (res[i] < minRes) {
                res[i] = 0;
            } else {
                res[i] = 1;
            }
        }
        return res;
    }
};

```