其实就是n位数，各个数字都不同的个数。
那么可以分成如下几种情况：
1. 0在首位，这种情况的个数其实就是n-1位数的个数
2. 0不在首位，而是其他位，那么就有(n-1) * A(9, n-1) 种，A是排列。
3. 没有0，A(9, n)

把上面三种加起来就能得到递推公式了
```c++
class Solution {
public:
    int A(int base, int i) {
        int prod = 1;
        for(int k = base;k>base-i;--k){
            prod *= k;
        }   
        return prod;
    }
    
    int countNumbersWithUniqueDigits(int n) {
        //if(n > 10) return 0; //超出10位数，必然至少有两位数字相同
        //vector<int> dp(n+1);
        int pre = 1; //这1个就是数字0
        for(int i=1;i<=n;++i){
            pre += (i-1) * A(9, i-1) + A(9, i);
        }
        return pre;
        
    }
};
```