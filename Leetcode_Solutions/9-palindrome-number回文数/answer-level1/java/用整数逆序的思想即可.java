### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int y=x,z=0;
        while(y!=0){
            z=z*10+y%10;
            y=y/10;
        }
        if(x==z){
            return true;
        }else{
            return false;
        }
    }
}
```