### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isArmstrong(int N) {
       String a=String.valueOf(N);
       int n=N;
       int sum=0;
       while(n!=0){
           sum+=Math.pow((n%10),a.length());
           n/=10;
       }
       return sum==N? true:false;
    }
}
```