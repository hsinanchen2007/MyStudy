### 解题思路
单调栈的模板在于两点
1. 遍历数组完成一次入栈
2. 处理栈中剩余的数组元素

本题从前向后遍历即可，维护一个递减栈。第一步，每遇到一个比栈顶元素大的数，就从栈中弹出一个，并对该元素所在的数组下标位置进行赋值。
第二步，即栈中剩余的数组元素，由于题目关系不用处理，数组默认值为0。

### 代码

```java
class Solution {
    public int[] dailyTemperatures(int[] T) {
        Stack<Integer> stack = new Stack<>();
        int[] nums = new int[T.length];
        for(int i = 0; i < T.length; i++){
            while(!stack.isEmpty() && T[stack.peek()] < T[i]){
                int j = stack.pop();
                nums[j] = i-j;
            }
            stack.push(i);
        }
        return nums;
    }
}
```