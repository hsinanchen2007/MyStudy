### 解题思路


### 代码

```java
class Solution {
    public String removeDuplicates(String S) {
        StringBuilder sb = new StringBuilder();
        int len = 0;
        for (char character : S.toCharArray()) {
            //如果栈中含元素(len!=0)且元素等于栈顶元素，则将该元素删除(出栈)
            if (len != 0 && character == sb.charAt(len - 1))
                sb.deleteCharAt(len-- - 1);
            //反之将元素添加(入栈)
            else {
                sb.append(character);
                len++;
            }
        }
        return sb.toString();
    }
}


```