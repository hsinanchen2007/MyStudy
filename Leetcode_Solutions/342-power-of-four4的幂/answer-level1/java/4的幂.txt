### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPowerOfFour(int num) {
        if(num==0)
        return false;
        else if(num==1)
        return true;
        double number=(double)num;
       while(number>4){
           number/=4;
       }
       if(number<4)
       return false;
       return true;
    }
}
```