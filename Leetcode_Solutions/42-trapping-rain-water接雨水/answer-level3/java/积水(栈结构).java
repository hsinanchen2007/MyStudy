### 解题思路
此处撰写解题思路
就是利用栈结构，降序（底到顶），存储可以积水的柱子，当不满足降序的时候，找到栈顶的左右两个边界，算出当前柱子可以积水面积，累加
### 代码

```java
class Solution {
    public int trap(int[] height) {
        // 采用栈结构进行计算，针对于每一根柱子，找出左右边界，算出当前柱子能够成多少水，时间复杂度为O(n)
        Stack<Integer> stack = new Stack<>();
        int area = 0;
        for(int i=0;i<height.length;i++){
            while(!stack.empty() && height[stack.peek()]<height[i]){
                int pop = stack.pop();
                if(stack.empty()){
                    break;
                }
                area = area +(i-stack.peek()-1)*(Math.min(height[i],height[stack.peek()])-height[pop]);
            }
            stack.push(i);
        }
        return area;
    }
}
```