### 解题思路
递归判断后两位数字是否可以翻译成两个字母

### 代码

```java
class Solution {
    public int translateNum(int num) {
        if(num <= 9) return 1;
        int two = num % 100;
        return translateNum(num / 10) 
            // 此时后两位可以翻译成一个字母
            + (two > 9 && two < 26 ? translateNum(num / 100) : 0);
    }
}
```