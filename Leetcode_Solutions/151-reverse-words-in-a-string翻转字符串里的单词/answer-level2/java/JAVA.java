### 解题思路
很简单的翻转，主要把特殊情况都卡掉

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        //去空格后的串长度小于1的，直接返回空串
        if(s.trim().length()<1){
            return "";
        }
        //分割字符串
        String[] a = s.split(" ");
        String str="";
        for(int i=a.length-1;i>=0;i--){
            if(a[i].length()>0){//跳过空串
                str+=a[i]+" ";
            }
        }
        //截掉最后一个空格
        str=str.substring(0,str.length()-1);
        return str;
    }
}
```