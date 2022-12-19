解法一：双端队列
```java
class Solution {
    public String simplifyPath(String path) {
        Deque<String> q = new ArrayDeque<>();
        for(String i : path.split("/")){
            if(i.equals("..")&&q.peek()!=null) q.removeLast(); 
            else if(!i.equals("..") && !i.equals(".") && !i.equals("")) q.addLast(i);
        }
        StringBuilder sb = new StringBuilder();
        while(q.peek()!=null){
            sb.append("/");
            sb.append(q.removeFirst());
        } 
        return sb.length() == 0 ?"/":sb.toString();
    }
}
```
解法二：栈
```java
class Solution {
    public String simplifyPath(String path) {
        Stack<String> s = new Stack<>();
        for(String i : path.split("/")){
            if(i.equals("..")&&!s.empty()) s.pop();
            else if(!i.equals("..")&&!i.equals(".") && !i.equals("")) s.push(i); 
        }
        StringBuilder sb = new StringBuilder();
        for(String a : s) {
            sb.append("/");
            sb.append(a);
        }
        return sb.length() == 0 ?"/":sb.toString();
    }
}
```