### 解题思路
此处撰写解题思路
将字符串转换成字符数组进行遍历
将遍历的结果放到StringBuffer中
如果遍历到空格的话则向StringBuffer中加“%20”
否则加入当前字符
### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuffer a = new StringBuffer();
        for(char c:s.toCharArray()){
            if(c ==' ')
                a.append("%20");
            else
                a.append(c);
        }
        return a.toString();
    }
}
```