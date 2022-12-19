### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int i=0,flag=1;//第i个字母
        char t;
        if(strs.length==0)
            return "";
        while(flag!=0){
            for(int j=0;j<strs.length;j++){
                if(i>=strs[j].length()){
                    flag=0;
                    break;
                }
                t=strs[0].charAt(i);
                if(t!=strs[j].charAt(i)){
                    flag=0;
                    break;
                }
             }
            i++;
        }
        if(i==0)
            return " ";
        else
            return strs[0].substring(0,i-1);
    }
}
```
提交n次，最后发现是没有对输入为[]进行判断，直接在开头加上判断即可
思路是对每个字符串从[0]位开始比较，直到字符不同或者超出字符串位数，跳出循环
已知字符串的前i位为公共前缀，使用函数截取字符串子串return