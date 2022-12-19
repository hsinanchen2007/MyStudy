```
class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();
        //使用正则表达式\s表示匹配任何空白字符，+表示匹配一次或多次;
        String[] ss = s.split("\\s+");

        for(int i=ss.length-1;i>=0;i--){
            if(!ss[i].equals(" ")){
                sb.append(ss[i]+" ");
            }
        }
        return sb.toString().trim();

    }
}
```
