### 解题思路
1. 找出最长字符串
2. 设置一个公共字符串（为空）
3. 将最长的字符串从第一位开始逐一连接到公共字符串后面
4. 逐一比对每一个字符串是否以公共字符串开始
5. 如果有一项不是则返回此公共字符串，否则从3开始重复执行

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n=0;
        String max="";
        StringBuffer comm=new StringBuffer();
        for (String s : strs) {
            if (n < s.length()){
                n = s.length();
                max=s;
            }
        }
        char[] commArray=max.toCharArray();
        boolean judge=true;
        boolean judgeFirst=true;
        for (char c : commArray) { 
            comm.append(c);       
            for (String s : strs) {
                if(s.equals(max))
                    continue;
                if (!s.startsWith(String.valueOf(comm))) {
                    judge = false;
                    comm.deleteCharAt(comm.length() - 1);
                    break;
                }
            }
            if (!judge)
                break;
        }
        return String.valueOf(comm);
    }
}
```