### 解题思路
代码思路很简单，一看就懂。
![image.png](https://pic.leetcode-cn.com/07e352e245887155b376504f6545d6bb4111039024a8574b7db44a0ec27cef5d-image.png)

### 代码

```cpp
#include <string>
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        for(int i = 1, max = pow(10,n); i < max; i++) //pow(10,n)，为10的n次方 10^n
            res.push_back(i);
        return res;
    }
};
```