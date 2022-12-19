### 解题思路
先取字符串数组中的最小字符串，把该字符串转为字符数组char[]，将char[]中的元素与剩下的字符串逐一比对
### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
 
 if (strs==null||strs.length==0) return "";
        String tmp1 = null;
      //获取最短的字符串
        for (int i = 0; i < 1; i++) {
            for (int j = i + 1; j < strs.length; j++) {
                if (strs[j].length() <= strs[i].length()) {
                    tmp1 = strs[i];
                    strs[i] = strs[j];
                    strs[j] = tmp1;
                }
            }
            tmp1 = strs[i];
        }

        char[] str1 = tmp1.toCharArray();
        tmp1 = "";
        int count=0;
        for (int i=0;i<str1.length;i++) {

            for (int j = 1; j < strs.length; j++) {

               // System.out.println("strs[j]:"+strs[j]);
                if (strs[j].indexOf(str1[i])==0){
                    strs[j]=strs[j].replaceFirst(""+str1[i], "");
                    //累计含有char[]中元素的字符串数
                    count++;
                }


            }

            if (count==strs.length-1) tmp1 += str1[i];
             else if (count<strs.length-1) break;
            count=0;
            //System.out.println(tmp1);

        }


        return tmp1;
    }

}
```