### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUgly(int num) {
        if(num==0)
            return false;

        while (num%2==0) {
            num=num/2;
        }

        while (num%3==0) {
            num=num/3;
        }

        while (num%5==0) {
            num=num/5;
        }

        if (num==1) {
            return true;
        }

        return false;
    }
}
```