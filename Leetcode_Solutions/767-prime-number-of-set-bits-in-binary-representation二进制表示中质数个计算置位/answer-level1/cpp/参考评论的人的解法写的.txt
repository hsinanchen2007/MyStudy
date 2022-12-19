其实主要就是两个模块，1是如何计算二进制化后数组中1的个数，而是如何前者判断是否为质数。

```
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        
        set<int> prime = {2,3,5,7,11,13,17,19};
        //题目的取值上限为10^6，而10^6转换为二进制最多只有20位，所以列出20位内的所有质数即可
        
        int sum=0;
        
        
        for(int num=L; num<=R; num++){
            
            int count=0;
            
            int temp = num;
            while(temp!=0){//通过连续与运算可以计算出1的个数
                
                temp = temp & temp-1;
                count++;
            }
            
            if(prime.count(count)==1)
                //bitset.count()可以返回数组内的1的个数，和质数集合对比，一致则返回值+1
                sum++;
            
        }
        
        return sum;
    }
};
```
