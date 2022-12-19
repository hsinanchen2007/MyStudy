### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int bitwiseComplement(int N)
    {
        if(N==0) return 1;
        int temp1 = 1;//000000...1
        int temp2 = N;
        while(temp2 > 0)
            {//不停用temp1对原整数进行异或运算，每次运算结束后将temp1朝左移动1位
            N = N ^ temp1;
            temp1 = temp1 << 1;
            temp2 = temp2 >> 1;//运算出口记录
        }
        return N;
    }
};
```