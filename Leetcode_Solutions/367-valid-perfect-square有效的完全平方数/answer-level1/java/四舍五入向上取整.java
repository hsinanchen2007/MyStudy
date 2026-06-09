### 解题思路

四舍五入向上取整在平方若还与远来的数相等则是完全平方数
### 代码

```java
class Solution {
    public boolean isPerfectSquare(int num) {  
         
        if( Math.floor(Math.sqrt(num))*Math.floor(Math.sqrt(num)) ==  num){
            return true;
        }
        return false;
    }
}
```