### 方法一：有栈
有栈：通过栈压栈出栈放入sb中

### 代码

```java
class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> sta = new Stack<Character>();
        StringBuilder sb = new StringBuilder();
        for(char c:S.toCharArray()){
            if(!sta.isEmpty() && c == sta.peek()) sta.pop();
            else sta.push(c);
        }
        for(char c:sta)
            sb.append(c);
        return sb.toString();
    }
}
```
### 方法二：无栈
无栈：直接使用sb进行加入删除操作

### 代码

```java
class Solution {
    public String removeDuplicates(String S) {
        StringBuilder sb = new StringBuilder();
        int len = 0;
        for(char c:S.toCharArray()){
            if(len!=0 && c == sb.charAt(len-1)) 
                sb.deleteCharAt(len-- -1);
            else{
                len++;
                sb.append(c);
            } 
        }
        return sb.toString();
    }
}
```