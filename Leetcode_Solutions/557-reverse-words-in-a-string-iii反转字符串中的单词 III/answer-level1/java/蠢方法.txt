先分开，单独翻转再拼接，把最后的空格删掉
```
class Solution {
    public String reverseWords(String s) {
        String[] ss=s.split(" ");
        String sss="";
        for(String x:ss){
            sss=sss+new StringBuilder(x).reverse().toString()+" ";
        }
        return sss.trim();
    }
}
```
