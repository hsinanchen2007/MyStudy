### 解题思路
1. 建立一个栈，用来保存路径上的目录
2. 从左往右遍历，分割出当前目录。若目录为".."，意为进入上一层目录，故将栈顶弹出；若不为"."，则将新目录入栈
3. 遍历栈，生成路径

### 代码

```java
class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<String>();
        String[] dirs = path.split("/");
        int index=path.indexOf("/");
        while(index!=-1){
            int second = path.indexOf("/",index);
            String dir = path.substring(index,second==-1?path.length():second);
            if(dir.equals("..")){
                if(!stack.isEmpty())
                stack.pop();
            }
            else if(dir.length()>0&&!dir.equals(".")){
                stack.push(dir);
            }
            index=second!=-1?second+1:-1;
        }
        String res="";
        for(String s:stack)
            res+="/"+s;
        if(res.length()==0)
            res="/";
        return res;
    }
}
```