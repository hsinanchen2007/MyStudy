### 解题思路
虽然是用的位运算，但可能不是主流的，完全按照自己的理解来的，暂时称之为暴力位运算法吧。
### 代码

```cpp
class Solution {
public:
    char getAlpha(int n){
        char temp[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        return temp[n];
    }
    string toHex(int num) {
        int bitArr[32] = {  0x00000000,0x00000001,0x00000003,0x00000007,0x0000000f,0x0000001f,0x0000003f,0x0000007f,
                            0x000000ff,0x000001ff,0x000003ff,0x000007ff,0x00000fff,0x00001fff,0x00003fff,0x00007fff,
                            0x0000ffff,0x0001ffff,0x0003ffff,0x0007ffff,0x000fffff,0x001fffff,0x003fffff,0x007fffff,
                            0x00ffffff,0x01ffffff,0x03ffffff,0x07ffffff,0x0fffffff,0x1fffffff,0x3fffffff,0x7fffffff};
        if (num == 0)
            return "0";
        string res = "";    int bit = 31;   vector<bool> temp;
        while (bit)
        {
            if (num >> bit)
            {
                temp.push_back(1);
                num = num & bitArr[bit];
            }
            else
                temp.push_back(0);
            bit--;
        }
        temp.push_back(num);
        for (int i=0; i<8; i++)
        {
            int f = 0;
            for (int j=0; j<4; j++)
                f = f * 2 + temp[i*4+j];
            if (getAlpha(f) == '0' && res == "")
                continue;
            res += getAlpha(f);
        }
        return res;
    }
};
```