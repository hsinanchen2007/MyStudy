### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        String xx=String.valueOf(x);
        if (xx.charAt(0)=='-'||xx.charAt(0)=='+'){
            return  false;
        }
        int rest;
        int b=0;
        while (x!=0){
            rest=x%10;
            x=x/10;
            b=b*10+rest;
        }

        if (xx.equals(String.valueOf(b))){
            return true;
        }
        return false;
    }
 
}
```