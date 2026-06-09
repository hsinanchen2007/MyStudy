### 解题思路
1.逆波兰表示法会保证运算符前面总会有两个数
2.遇到数字压栈，遇到符号退两次栈，按符号要求运算后压回栈，运算完毕以后，只有1个数字，返回。

### 代码

```java
class Solution {
    public int evalRPN(String[] tokens) {
        int[] nums = new int[tokens.length];
        int index = 0;
        for(String token : tokens){
            if(token.equals("+")){
                    nums[index-2] += nums[index-1];
                    index--;
                } else if(token.equals("-")){
                    nums[index-2] -= nums[index-1];
                    index--;
                } else if(token.equals("*")){
                    nums[index-2] *= nums[index-1];
                    index--;
                } else if(token.equals("/")){
                    nums[index-2] /= nums[index-1];
                    index--;
                } else {
                    nums[index++] = new Integer(token);
                }
        }
        return nums[0];
    }
}
```