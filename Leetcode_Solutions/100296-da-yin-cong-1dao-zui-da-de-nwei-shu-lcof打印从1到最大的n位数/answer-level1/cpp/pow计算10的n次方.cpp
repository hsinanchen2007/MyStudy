### 解题思路
此处撰写解题思路
使用cmath头文件中的库函数 pow(x,y)计算10的n次方 这里x,y都是double类型的值 pow返回double类型的值。

### 代码

```cpp
#include <cmath>

class Solution {
public:
    vector<int> printNumbers(int n) {
        int Num = (int)pow(10.0,n);
        vector<int> Res;
        for(int i=1;i<Num;i++)
        {
            Res.push_back(i);
        }
        return Res;
    }
};
```