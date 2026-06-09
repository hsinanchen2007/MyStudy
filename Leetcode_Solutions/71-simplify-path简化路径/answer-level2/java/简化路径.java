# 代码
```java []
class Solution {
    public String simplifyPath(String path) {
        if(path.length()==0 || path.length()==1) return path;
        Stack<String> st=new Stack(); 
        String[] ss=path.split("/");
        for(String a:ss){
            if(a.equals("..")){
                if(st.isEmpty()==false) st.pop();
            }
            else if(a.equals(".")==false && a.equals("")==false) st.push(a);
        }
        if(st.isEmpty()) return "/";
        StringBuilder sb=new StringBuilder();
        for(String str:st) sb.append("/"+str);
        return sb.toString();
    }
}
```
