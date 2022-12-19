1. 将字符串通过空格进行分割，如the sky is blue分割成 the，sky，is，blue
2. 然后通过str.trim().length()将所有"  "去掉。叠加到res。
```
class Solution {
    public String reverseWords(String s) {
        String arr[] = s.split(" ");
        String res = "";
        for (String str:arr){
            if(str.trim().length() != 0)
            res = str+" "+res;
        }
        return res.trim();
    }
}
```
