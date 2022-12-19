### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        String s = String.valueOf(x); //将int类型的x转换成String类型
        StringBuilder builder = new StringBuilder(s);
        //利用StringBuilder类中的反转函数reverse()
        String s1 = builder.reverse().toString();
        return s.equals(s1);
    }
}
```