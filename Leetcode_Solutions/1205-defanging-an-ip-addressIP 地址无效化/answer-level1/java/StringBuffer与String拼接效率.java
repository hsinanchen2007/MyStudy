### 解题思路
思路很简单，第一想法是如果用replace，但是这样的话，这题就没啥意思了。
所以就用循环判断，注意点：StringBuffer的拼接效率比较高。直接String做拼接会慢一点。因为要花时间创建新的字符串对象。

### 代码

```java
class Solution {
       public String defangIPaddr(String address) {
        StringBuffer result = new StringBuffer();
        char[] b = address.toCharArray();
        for (int i = 0; i < b.length; i++) {
            result = (b[i] + "").equals(".") ? result.append("[.]") : result.append(b[i]);
        }
        return result.toString();
    }
}
```