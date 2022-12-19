![image.png](https://pic.leetcode-cn.com/c822546c06e1d4190fe0adb6c8b00a91a2833033a44c182039de31102f4eca0e-image.png)


```
class Solution {
    public String toGoatLatin(String S) {
        String Ystr1 = "aeiou";
        String Ystr2 = "AEIOU";
        String [] Sarr = S.split(" ");
        StringBuilder ans = new StringBuilder();
        String indexStr = "a";
        for (int i = 0; i < Sarr.length; i++){
            StringBuilder sarr = new StringBuilder(Sarr[i]);
            if (!Ystr1.contains((sarr.charAt(0) + ""))&&!Ystr2.contains((sarr.charAt(0) + ""))){
                String temp = sarr.substring(1,sarr.length());
                ans.append(temp).append(Sarr[i].charAt(0)).append("ma").append(indexStr).append(" ");
            }else{
                ans.append(Sarr[i]).append("ma").append(indexStr).append(" ");
            }
            indexStr += "a";
        }
        
        return ans.substring(0,ans.length()-1);
    }
}
```
