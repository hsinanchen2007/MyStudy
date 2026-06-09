![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/bbdaff8205615e43d1474908a484670f31f4a63f7e7ae448c82d43a0da076fb7-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)

### 解题思路
建立一个辅助栈，模拟此过程

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        int j = 0;//需要对比的序号
        for(int i = 0; i<pushed.length; i++){
            stack.push(pushed[i]);
            while(!stack.isEmpty() && j<popped.length && stack.peek() == popped[j]){
                stack.pop();
                j ++;
            }
        }
        return stack.isEmpty();
    }
}
```