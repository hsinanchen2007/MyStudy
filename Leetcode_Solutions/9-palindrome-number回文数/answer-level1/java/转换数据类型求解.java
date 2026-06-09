### 解题思路
为了更加方便地使用循环来求解回文数，我们可以首先将整数转化为字符串，再将字符串变为char型数组。
注意，Java中字符串不能像C++一样直接按位置索引，需要转换。

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        String s = "";
        s = String.valueOf(x); //整数变为字符串
        char[] c = s.toCharArray(); //字符串变为char型数组
        int i = 0, j = s.length()-1;
        while(i <= j){ //while循环对称比较，因为回文数一定是对称的
            if(c[i] != c[j])
                return false;
            i++; j--;
        }
        return true;
    }
}
```