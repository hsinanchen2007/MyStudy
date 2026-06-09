### 解题思路
1：将字符串转化为字符数组
2：构建Set集合，利用set集合中，元素不可重复
3：循环将字符加入set集合中,判断set集合的大小是否等于字符数组的长度

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        Set s = new HashSet();
        char[] c = astr.toCharArray();
        for(int i=0;i<c.length;i++){
            s.add(c[i]);
        }
        return s.size() == c.length;
    }
}
```