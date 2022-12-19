```
class Solution {
    public String reverseWords(String s) {
            String[] a = s.split(" ");
            StringBuffer sb = new StringBuffer();
            for(int i = a.length-1;i>=0;i--){
                if(!a[i].equals(""))  {
                sb.append(a[i]);
                sb.append(" ");}
            }
            return sb.toString().trim();
           
    }
}
```
需要注意的是 如果字符串前面有空格 split() 会产生一个 ""
如果中间有连续的三个空格 会产生两个""
另外 String类型  用"=="无效   要使用equals() 方法判断