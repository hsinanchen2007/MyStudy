### 解题思路
用栈中的pop来模拟$..$操作

### 代码

```java
class Solution {
    public String simplifyPath(String path) {
        Stack stack = new Stack();
        String[] arr = path.split("/");
        for(String s : arr){
            if(s.equals(".") ||s.equals("")){
                continue;
            }
            else if(s.equals("..")){
                if(!stack.empty()){
                    stack.pop();
                }
            }
            else{
                stack.push(s);
            }
        }
        String res="";
        while(!stack.empty()){
            res = "/"+stack.pop() + res;
        }
        if(res.length()==0 && path.length()!=0){
            return "/";
        }
        return res;
    }
}
```