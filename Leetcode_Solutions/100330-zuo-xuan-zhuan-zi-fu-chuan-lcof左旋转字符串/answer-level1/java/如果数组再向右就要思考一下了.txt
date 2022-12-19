### 解题思路
    将要移动部分和不移动部分交换subString就行了；
    要是数组的话，要稍微繁琐一点；

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        int size = s.length();
        int rate = n % size;
        String leftPart = s.substring(0, rate);
        String rightPart = s.substring(rate, size);
        return rightPart + leftPart;
    }
}
```