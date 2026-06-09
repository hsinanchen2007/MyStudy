### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convertToBase7(int num) {
        if (num < 0) {
            return "-" + convertToBase7(0 - num);
        }
        if (num < 7) return "" + num;
        return convertToBase7(num / 7) + num % 7;
    }
}
```