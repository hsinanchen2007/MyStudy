### 解题思路
把整形换成字符串，用字符串分割的方法判断，不确定是否增加内存空间的使用

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        String n = String.valueOf(x);
        while(n.length() > 1 ){
            String start = n.substring(0,1);
            String end = n.substring(n.length()-1, n.length());
            if(!start.equals(end)){
                return false;
            }
            n = n.substring(1,n.length()-1);
        }
        return true;
    }
}
```