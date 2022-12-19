### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countPrimes(int n) {
        int []nums=new int[n];
        int count=0;
        for(int i=2;i<Math.sqrt(n);i++){
            if(isPrime(i)){
                int k = 2;
            while (k * i < n){
                nums[k * i] = 1;
                k++;
            }
                }
            }
            for(int i=2;i<n;i++){
                if(nums[i]==0)
                count++;
            }
            return count;
        }
        boolean isPrime(int n) {
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
    }
    
}
```