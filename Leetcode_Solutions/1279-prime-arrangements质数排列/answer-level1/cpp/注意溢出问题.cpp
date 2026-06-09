```c++ []
class Solution {
    bool isPrime(int n){
        if(n <= 1){
            return false;
        }    
        if(n == 2){
            return true;
        }
        int end = sqrt(n);
        for(int i = 2;i <= end; ++i){
            if(n%i == 0){
                return false;
            }
        }
        
        return true;
    }
    
    long long factorial(int n){
        long long ans = 1;
        int mod = 1000000007;
        
        for(int i = 2;i <= n; ++i){
            ans = (ans*i)%mod;
        }
        
        return ans;
    }
    
    int numPrimeArrangements(int n) {
        int prime = 0;
        int rest = 0;
        int mod = 1000000007;
        int ans = 0;
        
        for(int i = 2; i <= n; ++i){
            if(isPrime(i)){
                prime++;
            }
        }
        rest = n - prime;
        ans = (factorial(rest)*factorial(prime))%mod;
        
        return ans;
    }
};
```
```java []
class Solution {
    public boolean isPrime(int n){
        if(n <= 1){
            return false;
        }    
        if(n == 2){
            return true;
        }
        
        for(int i = 2; i*i <= n; ++i){
            if(n%i == 0){
                return false;
            }
        }
        
        return true;
    }
    
    public  long factorial(int n){
        long ret = 1;
        int mod = 1000000007;
        
        for(int i = 1;i <= n; ++i){
            ret = (ret*i)%mod;
        }
        
        return ret;
    }
    
    public int numPrimeArrangements(int n) {
        int prime = 0;
        int mod = 1000000007;
        long ans = 0;
        
        for(int i = 1;i <= n; ++i){
            if(isPrime(i)){
                prime++;
            }
        }
        
        ans = factorial(prime)*factorial(n-prime)%mod;
        return (int)ans;
    }
}
```