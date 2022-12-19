### 解题思路
如果n是偶数，则添加对称的数：i和-i
如果n是奇数，最中间的数为0


### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int[] res =new int[n];
        if(n%2==0){
            for(int i=0;i<n/2;i++){
                res[i]=-(i+1);
                res[n-i-1]=i+1;
            }
        }else{
            for(int i=0;i<n/2;i++){
                res[i]=-(i+1);
                res[n-i-1]=i+1;
                
            }
            res[n/2]=0;
        }
        return res;
    }
}
```