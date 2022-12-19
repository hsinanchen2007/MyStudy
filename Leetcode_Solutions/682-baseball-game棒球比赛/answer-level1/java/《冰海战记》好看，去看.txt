### 解题思路
![QQ截图20200304144038.png](https://pic.leetcode-cn.com/72f0da17139206fc82ed4734c40517a5a1c97c43ae3f51b6b406c53a26564a02-QQ%E6%88%AA%E5%9B%BE20200304144038.png)
栈顶元素始终是最近一次有效回合的分数
### 代码

```java
class Solution {
    public int calPoints(String[] ops) {
        int sum=0;
        Stack<String> stack=new Stack<>();
        for(int i=0;i<ops.length;i++){
            switch (ops[i]){
                case "C":
                    sum-=Integer.parseInt(stack.pop());
                    break;
                case "D":
                    sum+=2*Integer.parseInt(stack.peek());
                    stack.push(String.valueOf(2*Integer.parseInt(stack.peek())));
                    break;
                case "+":
                    sum+=(Integer.parseInt(stack.elementAt(stack.size()-1))+Integer.parseInt(stack.elementAt(stack.size()-2)));
                    stack.push(String.valueOf(Integer.parseInt(stack.elementAt(stack.size()-1))+Integer.parseInt(stack.elementAt(stack.size()-2))));
                    break;
                default://整数
                    stack.push(ops[i]);
                    sum+=Integer.parseInt(ops[i]);
                    break;

            }
        }
        return sum;

    }
}
```