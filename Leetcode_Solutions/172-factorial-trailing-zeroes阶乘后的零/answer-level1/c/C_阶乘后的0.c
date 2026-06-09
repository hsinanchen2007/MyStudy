### 解题思路
N!=1\*2\*3\*4\*5\*6\*7\*8\*9\*....\*N=1\*2\*3\*(2\*2)\*5\*(2\*3)\*7\*(2\*4)*9\*...\*N
结尾有只有2\*5才能使结尾有个0，而且根据观察，因子2每两个数就出现一次，而因子5每5个数字就出现一次，所以一定有足够的2和5相乘为10。根据交换律，可以把上式所有的2和5交换的到式子的开端。所以问题简化成了N!这个等式中到底有多少因子5.
参考：https://leetcode-cn.com/problems/factorial-trailing-zeroes/solution/xiang-xi-tong-su-de-si-lu-fen-xi-by-windliang-3/
### 代码

```c
int trailingZeroes(int n){
    int result=0;
    while(n>0)
    {
        n/=5;
        result+=n;
    }
    return result;
}
```