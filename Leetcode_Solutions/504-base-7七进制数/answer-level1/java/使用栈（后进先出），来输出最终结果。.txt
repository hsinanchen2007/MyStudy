### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convertToBase7(int num) {
        //特殊情况处理
        if (num == 0) return "0";

        Stack<Integer> stack = new Stack<>();
        int n = Math.abs(num);
        while(n > 0){
            stack.push(n % 7);
            n = n / 7;
        }

        StringBuilder sb = new StringBuilder();
        if (num < 0) sb.append("-");
        while(!stack.isEmpty()){
            sb.append(stack.pop());
        }

        return sb.toString();
    }
}
```