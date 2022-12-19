### 解题思路
假设string数组中的第一个字符串就是最长公共前缀，套进程序，发现不合适，就往回减掉一个字符，继续带入程序
如果到最后都不是公共的  说明就没有公共前缀

执行用时 :1 ms, 在所有 Java 提交中击败了84.91%的用户
内存消耗 :37.1 MB, 在所有 Java 提交中击败了80.99%的用户

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
       if(strs.length == 0)
            return "";

        //任意取strs中的一个字符串
        StringBuffer temp = new StringBuffer(strs[0]);

            
        
        for(String str: strs){
            while(!str.startsWith(temp.toString())){
                if(temp.length() == 1)
                    return "";
                temp = temp.deleteCharAt(temp.length() - 1);
            }
        }   
        return temp.toString();
    }
}
```