### 解题思路
1.如果数据为null 则是空
2.如果数组为1，这最大公共前缀就是第一个元素
3.除了前面两种情况，初始假设最大公共前缀的长度为数组第一个元素的长度，然后从数组第二个元素开始遍历数组
4.在循环里面分别拿数组的其他元素跟第一个元素去做字符比较然后确定当前元素和第一个元素的最大前缀长度，
并且取当两元素和第一个元素最大匹配长度跟上一个元素和第一个元素的最大匹配长度的较小值。
5.最终循环完后截取字符串

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0){
            return "";
        }
        if(strs.length==1){
            return strs[0];
        }
        String str = strs[0];
        int sns = str.length();
        for (int i = 1; i < strs.length; i++) {
            int min = Math.min(str.length(),strs[i].length());
            if(min==0) return "";
            for (int j = 0; j < min; j++) {
                if(str.charAt(j) != strs[i].charAt(j)){
                    sns = Math.min(sns,j);
                    break;
                } else{
                    sns = Math.min(sns,min);
                }             
            }
        }
        if(sns<=0){
            return "";
        }
        return str.substring(0,sns);
    }
}
```