### 解题思路
此处撰写解题思路
最近这样的脑筋急转弯类型的题目越来越多了，感觉考得就是对于数字的整体感觉
例如 
x/div求的是最左一位
x%10求最右一位
while(x/div >= 10){
            // div = div*10;
            div *=10;
        }
这段求的是 最高是在哪一位上
### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        int div = 1;
        while(x/div >= 10){
            // div = div*10;
            div *=10;
        }
        while(x != 0 ){
            int left = x/div;
            int right = x%10;
            if(left !=right) return false;
            else {
                //求去掉中间的数字
                x = (x - left*div)/10;
                div /=100;
                
            }
        }
        return true;
    }
}
```