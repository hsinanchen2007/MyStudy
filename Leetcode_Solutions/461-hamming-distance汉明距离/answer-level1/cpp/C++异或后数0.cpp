两个数字对应二进制位不同位置的数目，那就是看这两个数字异或后二进制位上1的个数。
统计1的个数有很多种，而我使用的是传统的
```python
while n不是0:
    说明找到一个1,count++
    n被n和n-1的&运算结果替代
```
找到多少个1就遍历多少次，为什么这样呢？其实画一下图就知道了
拿10010为例子
第一次:10010不是0，10010 & 1101 = 10000
第二次:10000不是0，10000 & 1111 = 0
数1是从右往左数的。


完整代码如下
```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n=x^y;
        int count=0;
        while(n!=0){
            n=n&(n-1);
            count++;
        }
        return count;
    }
};
```
