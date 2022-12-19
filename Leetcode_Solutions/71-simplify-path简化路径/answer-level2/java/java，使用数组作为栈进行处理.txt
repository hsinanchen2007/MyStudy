### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String simplifyPath(String path) {
        //        String[] pathArr =  path.split("/+"); 则会导致时间多一倍，使用正则表达式
           String[] pathArr =  path.split("/");
        // 数组当做栈
        String[] ans =  new String[pathArr.length];
        // 栈顶指针
        int index = 0;
        for (int i = 1; i < pathArr.length; i++){
            //出栈不为空 
            if ("..".equals(pathArr[i]) && index > 0)
                index--; // pop
            else  if (!pathArr[i].equals("") && !pathArr[i].equals(".") && !pathArr[i].equals("..")) {
                ans[index++] = pathArr[i];
            }
        }
        if (index == 0)
            return "/";
        StringBuilder stringBuilder = new StringBuilder();
        for ( int i = 0; i < index; i++)
            stringBuilder.append("/" + ans[i]);
        return stringBuilder.toString();
    }
}
```