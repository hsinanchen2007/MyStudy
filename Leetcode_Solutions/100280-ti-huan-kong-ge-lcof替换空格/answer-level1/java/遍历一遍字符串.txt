![2020030501.PNG](https://pic.leetcode-cn.com/975a971f127884abf003ffdf6354b9fee904cf7d7ecac6b8063c3ef3d1b881fb-2020030501.PNG)

### 解题思路
声明StringBuilder sb,

遍历一遍字符串,每次遇到空格' ',将空格' '转换为"%20"添加到sb中,

最后返回sb.toString();
### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==' '){
                sb.append("%20");
            }else{
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}
```