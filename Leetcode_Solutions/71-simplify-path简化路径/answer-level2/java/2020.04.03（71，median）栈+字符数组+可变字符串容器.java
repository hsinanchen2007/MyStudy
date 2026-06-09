### 解题思路
本题使用了三种容器来求解绝对路径

- 首先定义栈用来存储**路径信息**，定义字符数组 `str` 来**分隔字符串**

- 依次遍历字符数组内容，这里使用**增强型** `for` 循环，如果是 `“..”` 还要**再判断是否为空**才能弹出栈

- 如果不为空也不为 `“.”` 这说明当前元素**是路径信息**，入栈即可

- 最后遍历完之后，先判断栈中**是否有元素**，没有则返回 `“/”`

- 如果有元素，则使用 `StringBuilder` 来存放**可变字符串**，最后返回 `ans` 即可。

### 代码

```java []
class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<>();
        // 首先将字符串以 “/” 分隔存储到新的字符数组 str 中
        String[] str = path.split("/");
        for (String s : str) {
            // 如果数组非空,且访问到的是 “..” 则说明要返回上一级,要将当前元素出栈
            if ( s.equals("..") ) {
                // 这里用到增强型 for 循环不能同时判断，需要再次判空
                // 而普通 for 循环则可写成( !stack.isEmpty() && s.equals("..") )
                if ( !stack.isEmpty() ) {
                    stack.pop();
                }                
            // 如果数组非空并且当前元素不是 “.” 说明当前元素是路径信息，要入栈
            } else if ( !s.equals("") && !s.equals(".") ) {
                stack.push(s);
            }
        }
        // 如果栈内没有元素说明没有路径信息，返回 “/” 即可
        if ( stack.isEmpty() ) {
            return "/";
        }
        // 这里用到 StringBuilder 操作字符串，效率高
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < stack.size(); i++) {
            ans.append( "/" + stack.get(i) );
        }
        return ans.toString();
    }
}
```