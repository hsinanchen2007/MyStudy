### 解题思路
如果原始嵌套深度是偶数，例如 6，重组的嵌套深度 = 3；
如果原始嵌套深度是奇数，例如 7，重组的嵌套深度 = 4。

找到规律相当于最大深度等于最大度的余2

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result;
        int d = 0;
        for (char &s: seq) {
            if (s == '(') {
                d++;
                result.push_back(d % 2);
            } else {
                result.push_back(d % 2);
                d--;
            }
        }
        return result;
    }
};
```