假设有 n 只水桶，可以测试m次，需要x只猪找出 “有毒” 水桶：
每一只猪有m+1中状态（第一次测试死，第二次死，....，一直活着）
所以，x只猪所能表达的状态有(m+1)^x
n>=(m+1)^x 求出x。
具体地，将水桶按x位(m+1)进制编码。
```
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        double res;
        int m=minutesToTest/minutesToDie;
        res = ceil(log(buckets)/log(m+1));
        return res;
    }
};
```
