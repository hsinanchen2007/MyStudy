### 解题思路
方法：(位运算) O(n)
我们可以一一枚举每个数，然后统计出其二进制表示中1的个数s，再判断s是否是质数。

由于L, R均不大于1000000，所以其二进制表示最多有20位，我们可以预先将20以内的所有质数都存到哈希表中，
然后就可以 O(1) 判断s是否是质数。

判断整数x的第k位是否是1，可以使用位运算：x >> k & 1。

### 代码

```cpp
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res=0;
        unordered_set<int> primes;
        int ps[] = {2,3,5,7,11,13,17,19};
        for(auto p: ps) primes.insert(p);//哈希表存入20以内的质数

        for(int i=L;i<=R;i++){
            int tmp=0;
            for(int j=i;j;j>>=1){
                if(j & 1){//判断当前位是否为1
                    tmp++;
                }
            }
            if(primes.count(tmp)){
                    res++;
                }
        }
        return res;
    }
};
```