### 解题思路
单调栈

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if(height.length < 3) return 0;// 不足以构成V型，直接退出
        int total = 0 ,top=0; // total用来存储最终存水量，top存储栈顶元素
        Stack<Integer> stack = new Stack<>();

        for(int i = 0; i < height.length; i++){
            //因为栈内是单调减的，当height[i] > height[stack.peek()]时， 就会构建出V形状
            while(!stack.empty() && height[i] > height[stack.peek()]){
                top = stack.pop();
                if(stack.empty()) break; // 如果stack 为空，没有说明左边界，无法构成V形状
                total += (Math.min(height[i],height[stack.peek()]) - height[top]) * (i - stack.peek() -1);
            }
            stack.push(i);
        }
        return total;
    }
}
```