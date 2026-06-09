### 解题思路
1、找出最短字符串
2、外层循环，依次去掉末尾字符，形成待比对字符
3、内层循环，将待比对字符与字符串数组中字符串对应长度子串依次比较，若不相同，则缩短待比对字符
4、若内层循环全部走完的，则说明待比对字符串与字符串数组中所有字符串都相同，则已经找到最长公共前缀，
此时，可跳出循环体，并输出结果

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String res = "";
        if (strs==null||strs.length==0){
            return res;
        }

        String minStr = strs[0];

        for (int i = 0;i<strs.length;i++){
            if (strs[i].length()<minStr.length()){  //找出最短字串
                minStr = strs[i];
            }
        }

        int len = minStr.length();
        while(len>0){
            int i;
            for (i = 0;i<strs.length;i++){
                String temp = strs[i].substring(0, len);   //取对应长度的子串
                if (!temp.equals(minStr)){
                    len--;
                    minStr = minStr.substring(0, len);
                    break;
                }
            }
            if (i==strs.length){
                res = minStr;
                break;
            }
        }

        return res;
    }
}
```