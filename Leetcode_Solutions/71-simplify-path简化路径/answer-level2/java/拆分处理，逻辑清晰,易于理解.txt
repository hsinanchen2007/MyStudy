### 解题思路
  以'/'作为分隔符,来截取分隔符之间的字符来判断:
  ".." 说明需要回到上一级目录，此时只需要将上一个'/'之间的字符清除即可
  使用stack数据结构;
### 代码

```java
class Solution {

    private void handle(Deque<String> s,String p){
        if(!s.isEmpty()&&"..".equals(p)){//回到上一级目录
            s.pop();
        }else if(!"".equals(p)&&!".".equals(p)&&!"..".equals(p)){
            s.push(p);
        }
    }
    public String simplifyPath(String path) {
        Deque<String> s = new ArrayDeque<>();
        int slash=0;//记录上一个斜杠出现的索引
        for(int i=1;i<path.length();i++){
            if(path.charAt(i)=='/'){
                String p=path.substring(slash+1,i);//截取两个斜杠之间的字符
                handle(s,p);//对两个斜杠之间的字符做处理
                slash=i;
            }
        }
        handle(s,path.substring(slash+1));//处理最后一段字符
        if(s.isEmpty()) return "/";
        StringBuilder sb = new StringBuilder();
        while (!s.isEmpty()){
            sb.append('/').append(s.pollLast());
        }
        return sb.toString();
    }
}
```