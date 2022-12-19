![微信截图_20191020104319.png](https://pic.leetcode-cn.com/56a8d688f78eb78313761a4f1b9f59117788bee0d2c81b55a57e6423fa489d26-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191020104319.png)

```
class Solution {
    public String reverse(String s){
        StringBuilder builder = new StringBuilder();
        
        for(int i = s.length()-1; i >= 0; i--){
            builder.append(s.charAt(i));
        }
        
        return builder.toString();
    }
    public String reverseWords(String s) {
        String[] str = s.split(" ");
        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < str.length; i++){
            builder.append(reverse(str[i]));
            if(i != str.length-1)
                builder.append(" ");
        }
        
        return builder.toString();
    }
}
```
