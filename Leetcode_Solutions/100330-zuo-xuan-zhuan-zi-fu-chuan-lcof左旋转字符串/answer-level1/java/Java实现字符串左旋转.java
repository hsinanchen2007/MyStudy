### 解题思路
主要考察String中subString()方法的用法
1.调用substring方法，可以先截取需要反转的字符串
2.使用substring获取不需要反转的字符串
3.拼接这两个字符串

### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
          if(s.length()==1){
            return s;
        }

        String temp = s.substring(0,n);
        String res = s.substring(n);
        s = res+temp;
        return s;
    }
}
```