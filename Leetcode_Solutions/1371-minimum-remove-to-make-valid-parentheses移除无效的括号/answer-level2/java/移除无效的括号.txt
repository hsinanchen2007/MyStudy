### 解题思路
单纯遍历字符串，无法判断（是否有效，需要用数据结构存储先出现的（，后续有匹配的）才是有效的，前面的（才是有效的

### 代码

```java
class Solution {
    public String minRemoveToMakeValid(String s) {
       StringBuffer sb =  new StringBuffer();
        Stack<Integer> stack = new Stack();
        // 标记每一位是否有效
        int[] valid = new int[s.length()];
        for (int i = 0; i< s.length(); i++) {
            char v = s.charAt(i);
            if (v == '(') {
                stack.push(i);
                valid [i] = 0;
            } else if (v == ')') {
                if (!stack.empty()) {
                    valid[stack.pop()] = 1;
                    valid[i] = 1;
                } else {
                    valid[i] = 0;
                }
            } else {
                valid[i] = 1;
            }
        }
        for (int i = 0; i< s.length() ; i++) {
            if (valid[i] == 1) {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    } 
    
}
```