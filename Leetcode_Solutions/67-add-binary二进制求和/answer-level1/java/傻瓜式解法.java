### 解题思路
遍历字符串 逐项相加即可。。
### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
         char[] chara = a.toCharArray();
        char[] charb = b.toCharArray();
        int indexa = chara.length-1;
        int indexb = charb.length-1;
        char tempa, tempb;
        int forword = 0;
        StringBuilder sb = new StringBuilder();
        while (indexa >= 0 || indexb >= 0) {
            tempa = indexa >= 0 ? chara[indexa--] : '0';
            tempb = indexb >= 0 ? charb[indexb--] : '0';
            if(tempa==tempb){
                if(tempa=='0'){
                    if(forword==0){
                        sb.append(0);
                    }else{
                        sb.append(1);
                        forword=0;
                    }
                }else{
                    if(forword==0){
                        sb.append(0);
                    }else{
                        sb.append(1);
                    }
                    forword=1;
                }
            }else{
                if(forword==0){
                    sb.append(1);
                }else{
                    sb.append(0);
                    forword=1;
                }
            }
        }
        if(forword>0){
            sb.append(forword);
        }
        //遍历sb 倒序输出
        return sb.reverse().toString();
    }
}
```