### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int arrangeCoins(int n) {
        if(n==0||n==1)
        return n;
        int count=0,k=0;
     for(int i=1;i<=n;i++){
         count+=i; k++;
         if(count>n||count<0){
           break;
         }
         else if(count==n)
         return i;
     }
     return k-1;
    }
}
```