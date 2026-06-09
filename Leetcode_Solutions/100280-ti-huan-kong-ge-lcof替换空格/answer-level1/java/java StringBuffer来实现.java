![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/7d46ad9926d00260a5524c841eb4d9c2271a235274bdd4e40172284b66efbdb7-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuffer sb = new StringBuffer();
        char c;
        for (int i = 0; i < s.length(); i++) {
            if ((c = s.charAt(i)) == ' ') {
                sb.append("%20");
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
```