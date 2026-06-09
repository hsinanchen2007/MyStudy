### 解题思路
先求异或,再求异或后1的个数

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        //先求异或
        //再求异或后1的个数
        int temp = x^y;
        int cnt=0;
        while(temp)
        {
            ++cnt;
            temp = temp&(temp-1);
        }
        return cnt;
    }
};
```