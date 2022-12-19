1. 按“/”得到paths.
2. 过滤 “.”,""
3. ".."记录需要倒退的步数 到back.
4. back>0 且没被过滤， back--
5. back ==0 , insert到最前面. 类似于 “c”,"ab" 在insert之后得到“abc”.

### 代码

```java
class Solution {
    public String simplifyPath(String path) {
        int back = 0;
        String[] paths = path.split("/");
        Stack<String> stack = new Stack();
        for(String p : paths){
            stack.push(p);
        }
        StringBuilder sb  = new StringBuilder();
        while(!stack.empty()){
            String s = stack.pop();
            if(s.isEmpty())
                continue;
            if(s.equals("."))
                continue;
            if(s.equals("..")){
                back++;
                continue;
            }
            if(back>0)
                back--;
            else{
                sb.insert(0,s);
                sb.insert(0,"/");
            }
        }
        return sb.length()==0?"/":sb.toString();
    }
}
```