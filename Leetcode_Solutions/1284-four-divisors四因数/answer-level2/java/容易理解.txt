### 解题思路
注意两点：除1和本身以外的第一对能整除的因数是质数；本身是立方数

### 代码

```java
class Solution {
    public int sumFourDivisors(int[] nums) {
        int sum=0;
        for(int num:nums){
            for(int i=2;i<Math.sqrt(num);++i){
                if(num%i==0&&prim(i)&&(prim(num/i)||num/i==i*i))sum=sum+1+num+i+num/i;
            }            
        }        
        return sum;
    }
    public boolean prim(int x){
        for(int i=2;i<x;++i){
            if(x%i==0)return false;
        }
        return true;
    }
}
```