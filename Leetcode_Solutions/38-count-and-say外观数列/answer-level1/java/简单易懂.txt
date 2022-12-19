### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        StringBuilder sb = new StringBuilder();
        String num = "1";
        while(n > 1){
           int length = num.length();
           int count = 0;
           StringBuilder str = new StringBuilder();
           while(length > count){
               int left = count;
               int right = left+1;
               while(right < length && num.charAt(left) == num.charAt(right)){
                   right++;
               }
               str.append(right -left).append(num.charAt(left));
               count = right;
           }
           n--;
           num = str.toString();
        }
        return num;
    }
}
```