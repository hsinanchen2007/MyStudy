### 解题思路
当前柱子如果小于等于栈顶元素，说明形不成凹槽，则将当前柱子入栈；反之若当前柱子大于栈顶元素，说明形成了凹槽，于是将栈中小于当前柱子的元素pop出来，将凹槽的大小累加到结果中。
单调栈就是比普通的栈多一个性质，即维护栈内元素单调。
    例。当前某个单调递减的栈的元素从栈底到栈顶分别是：[10, 9, 8, 3, 2]，如果要入栈元素5，需要把栈顶元素pop出去，直到满足单调递减为止，即先变成[10, 9, 8]，再入栈5，就是[10, 9, 8, 5]。


### 代码
/*单调栈问题*/
```java
class Solution {
    public int trap(int[] height) {
        if(height == null){
            return 0;
        }
        Stack<Integer> stack = new Stack<>();
        int ans = 0;
        for(int i=0; i<height.length; i++){
            while(!stack.isEmpty() && height[stack.peek()] < height[i]){
                int curIdx = stack.pop();
                while(!stack.isEmpty() && height[stack.peek()] == height[curIdx]){
                    stack.pop();
                }
                if(!stack.isEmpty()){
                    int stackTop = stack.peek();
                    ans += (Math.min(height[stackTop],height[i])-height[curIdx]) * (i-stackTop-1);
                }
            }
            stack.add(i);
        }
        return ans;
    }
}
```