### 解题思路
这道题的思路源于递归，先假设已知n-1个台阶的跳法总数，怎么求n个台阶的跳法总数呢？
首先明白所有的跳法都以1、2结尾，在增加一个台阶后，以2结尾的走法只能加一步，跳法数不变；而以1结尾的走法能够加一步完成跳跃，即继续以1结尾，又可以把最后两个一步合成两步到位；
意思就是，在增加一个台阶之后增加的跳法数就是上次以1结尾的跳法数；另外可以注意到，n个台阶的跳法中以1结尾的跳法数等于n-1个台阶的跳法总数；
总结：
n个台阶跳法数 = n-1个台阶跳法总数 + n-1个台阶以1结尾的跳法数 = n-1个台阶跳法总数 + n-2个台阶跳法总数


### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 3) {
            return n;
        }
        int bb_count = 1;
        int b_count = 1;
        int count = 2;
        for (int i = 3; i <= n; i++) {
            bb_count = b_count;
            b_count = count;
            count = (bb_count + b_count) % 1000000007;
        }
        return count;
    }
};
```