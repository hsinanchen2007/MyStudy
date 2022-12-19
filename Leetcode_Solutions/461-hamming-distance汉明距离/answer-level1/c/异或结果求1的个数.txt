### 解题思路
这道题其实就是求1个数的变式：
1.先经过异或操作求得两个数不同的数
2.再判断x^y结果中含有1的个数
### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x ^ y;
        int num = 0;
        for(int i=0;i<32;i++)
        {
            if(tmp & (1<<i))
                num++;
        }
        return num;
    }
};
```