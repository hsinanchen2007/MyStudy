### 解题思路
此处撰写解题思路
记住这个函数，任何进制都不是问题。
### 代码

```java
class Solution {
    public String convertToBase7(int num) {
        return Integer.toString(num,7);
    }
}
```