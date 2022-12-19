如果分解出1、两个质数2、一个小的质数和和它的平方3、特殊情况2*4=8。
```
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(auto num:nums){            
            for(long long i=2;i<=sqrt(num);i++){
                if(num%i==0){
                    long long another_i=num/i;
                    if(i==another_i) break;
                    else if((isprime(i)&&isprime(another_i))||(isprime(i)&&i*i==another_i)||(i==2&&another_i==4)){
                        res+=1+num+i+another_i;
                           break;
                    }                    
                }                
            } 
        }
        return res;
    }
    bool isprime(long long a){
        if(a==2) return true;
        for(long long i=2;i<=sqrt(a);i++){
            if(a%i==0) return false;
        }
        return true;
    }
};
```


