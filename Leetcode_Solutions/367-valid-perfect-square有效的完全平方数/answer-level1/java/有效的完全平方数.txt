### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPerfectSquare(int num) {
        if(num<2)return true;
        long i=0,j=num/2,x=0;
        while(i<=j){
            x=i+(j-i)/2;
            if(num<x*x)
            j=x-1;
            else if(num>x*x)
            i=x+1;
            else return true;
        }
        return false;
    }
}
```