### 解题思路
利用栈的思路判定当前这个括号应该分给谁

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int index = 0;
        int sizeA = 0;
        int sizeB = 0;
        vector<int> result(seq.size());
        
        for(char c: seq) {
            if (sizeA > sizeB) {
                if (c == ')') {
                    sizeA--;
                    result[index++] = 0;
                } else {
                    sizeB++;
                    result[index++] = 1;
                }
            } else {
                if (c == ')') {
                    sizeB--;
                    result[index++] = 1;
                } else {
                    sizeA++;
                    result[index++] = 0;
                }
            }
        }
        return result;
    }
};
```