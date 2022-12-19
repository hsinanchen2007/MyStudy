### 解题思路
用布赖恩·克尼根算法，执行一次即可去掉最右边的一个1
（右移位运算也可）

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int bit = x ^ y;
        int count = 0;
        while(bit){
            bit &= bit-1; //布赖恩·克尼根算法
            count++;
        }
        return count;
    }
};
```