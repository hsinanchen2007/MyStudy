### 解题思路
1、找规律：实例1、2、3都是可以看出是单词反转，而且单词之间都是用空格分开，多余的空格不需要
2、找方式：String类型里面就有现成的方法，去空格trim、根据空格分隔split

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        if (s == null) return s;
        String[] sps = s.split(" ");
        StringBuffer sb = new StringBuffer();
        for (int i=sps.length-1;i>=0;i--) {
            if ("".equals(sps[i].trim())) continue;
            sb.append(sps[i]).append(" ");
        }
        return sb.toString().trim();
    }
}
```