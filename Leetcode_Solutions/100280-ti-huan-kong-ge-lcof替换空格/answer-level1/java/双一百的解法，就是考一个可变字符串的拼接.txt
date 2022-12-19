```
class Solution {
    public String replaceSpace(String s) {
        //就是考一个string的不可变性，找个StringBuffer或者StringBulider来拼接。
        //StringBuffer为sychronized修饰线程安全。StringBuilder为线程不安全类。
        StringBuilder sb = new StringBuilder() ;
        for(int i=0;i<s.length();i++){
            if(String.valueOf(s.charAt(i)).equals(" ")){
                sb.append("%20");
            }else{
                sb.append(s.charAt(i)) ;
            }
        }
        return String.valueOf(sb) ;
    }
}
```
