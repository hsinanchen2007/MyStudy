```
class Solution {
public:
    int reverse(int x) {
        if(x/10 == 0) return x; //平凡情况：若x∈[-9,9]，则直接返回其本身
        int y = 0;
        while(x) {
            if(y > INT_MAX/10 || y < INT_MIN/10) //溢出
                return 0;
            y *= 10;
            y += x%10; //取出x的个位，存入y中对称的位置
            x /= 10;   //去掉x的个位
        }
        return y;
    }
};
```
- ***y == INT_{MIN, MAX}/10时可不可能溢出呢？***
设参数x的最高位为a，若y == INT_{MIN, MAX}/10，则y == ±214748364a, x == ±a463847412。
x为int型的输入参数，所以**a只能等于1**；故 **y == INT_{MIN, MAX}/10** 时不可能溢出。

- 一开始没注意到题目要求（“假设我们的环境只能存储得下32位的变量”），使用了long型的变量，感谢[@sha-sha-de-wo](/u/sha-sha-de-wo/)、[@chong-cai-de-xiao-peng-you](/u/chong-cai-de-xiao-peng-you/)指正。
![Leetcode_07_整数反转_题目要求.jpg](https://pic.leetcode-cn.com/94ee1034f8de3586f0f017a6381c46a479dd1be46f629de0763486ff3b7737f2-Leetcode_07_%E6%95%B4%E6%95%B0%E5%8F%8D%E8%BD%AC_%E9%A2%98%E7%9B%AE%E8%A6%81%E6%B1%82.jpg)
```
            long y = 0;   // 不符合题目要求
            while(x) {
            if(y > INT_MAX || y < INT_MIN)
                return 0; // 溢出
            // ......
            }
```
- 运行开销如下图所示：
![Leetcode_7_整数反转.png](https://pic.leetcode-cn.com/1639c057d708bd76158f4a5a30ca8c893d020d4469849da7c59e7cb5780bdbec-Leetcode_7_%E6%95%B4%E6%95%B0%E5%8F%8D%E8%BD%AC.png)






