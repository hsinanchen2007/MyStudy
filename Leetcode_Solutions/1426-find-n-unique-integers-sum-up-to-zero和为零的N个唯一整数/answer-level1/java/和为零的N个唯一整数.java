### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int []num=new int[n];
        int x=0;
         for(int i=1;i<=n/2;i++){
         num[x++]=i;
         num[x++]=-i;
         }
         if(n%2==1)
         num[x++]=0;
      return num;
    }
}
```