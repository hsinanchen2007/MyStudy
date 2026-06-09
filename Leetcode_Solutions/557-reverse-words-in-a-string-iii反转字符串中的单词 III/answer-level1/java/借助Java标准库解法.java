### 解题思路
借助Java标准库解法

### 代码

```java
class Solution {

    //
    public String reverseWords(String s) {
        if(s == null) {
            return s;
        }
        StringBuilder sb = new StringBuilder(s);
        String[] arr = sb.reverse().toString().split(" ");
        StringBuilder sb1 = new StringBuilder();
        for (int i = arr.length - 1; i >= 0; --i) {
            sb1.append(" " + arr[i]);
        }

        return sb1.toString().trim();
    }
}
```