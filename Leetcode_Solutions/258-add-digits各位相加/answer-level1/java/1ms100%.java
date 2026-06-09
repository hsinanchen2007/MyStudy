### 解题思路
此处撰写解题思路
### 代码

```java
class Solution {
    public int addDigits(int num) {
        while (num>=10) {
            int n=0;
            while (num > 0) {
                n += num % 10;
                num /= 10;
            }
            num = n;
        }
        return num;
    }
}
```