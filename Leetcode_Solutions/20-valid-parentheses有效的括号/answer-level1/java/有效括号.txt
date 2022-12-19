### 解题思路
栈的思路,左括号入栈,遇见右括号出来最后一个压入进去的左括号,匹配就继续,但栈里为空或不匹配就返回false,最后判断栈里还没有左括号剩余,有则返回false,我使用String数组代替了一下栈

### 代码

```java
class Solution {
    public boolean isValid(String s) {
        String[] strings = new String[s.length()/2 + 1];
		int j = 0;
		Map<String, String> map = new HashMap<>();
        map.put("(",")");
        map.put("{","}");
        map.put("[","]");
        String str;
        for(int i=0; i<s.length(); i++) {
            str = s.substring(i, i+1);
            if(map.containsKey(str)) {
            	strings[j++] = str;
            } else {
                if (j==0 || !str.equals(map.get(strings[--j])))
                    return false;
            }
        }
        return j==0;
    }
}
```