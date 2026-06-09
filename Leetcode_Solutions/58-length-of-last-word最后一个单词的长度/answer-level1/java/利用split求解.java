### 解题思路
用了split，思路很简单，但是执行用时很长，

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        String[] str = s.split(" ");
        if(str.length>0){
            return str[str.length-1].length();
        }else{
            return 0;
        }
    }
}
```