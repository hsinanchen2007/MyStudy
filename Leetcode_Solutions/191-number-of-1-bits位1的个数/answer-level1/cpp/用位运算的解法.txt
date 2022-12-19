# 位运算解法
很简答就是用n = n & (n-1),理解起来就是一个数首先化成二进制数，如36化成二进制100100，那么它的（n-1）
就是100011，很明显，(n-1)会把n的最右边的一个1借走，并把原本右边的0，都变成1，此时如果与 n 进行与运算，
那么就会得到 n 去掉最右边1的效果，利用这个性质，可以数出n中1的个数。```
代码块
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){
            n = n & (n-1);
            ++count;
        }
        return count;
    }
};
