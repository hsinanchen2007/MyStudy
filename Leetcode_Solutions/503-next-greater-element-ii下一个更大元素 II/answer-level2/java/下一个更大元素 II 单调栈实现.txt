### 解题思路
栈内维持一个从栈顶到底部从小到大,当下一个元素大于栈顶元素时候,就是nums[stack.peek()]<nums[i]说明nums[i]就是栈顶元素的下一个大的值,弹出栈顶元素,并且将nums[i]赋值到栈顶对应的索引位置
如果nums[i]<=nums[stack.peek()]直接将nums[i]压栈
应为是循环数组,索引将数组遍历两遍即可实现循环数组,通过取模来计算索引位置

### 代码

```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer> stack=new Stack<>();
        int length=nums.length;
        int[]result=new int[length];
        //初始化数组
        for(int i = 0; i < result.length; i++) {
            result[i] = -1;
        }
        for(int i=0;i<2*nums.length-1;i++){
            //判断栈顶元素与nums[i%length]的大小
            while(!stack.isEmpty()&&nums[stack.peek()]<nums[i%length]){
                result[stack.pop()]=nums[i%length];
            }
            //满足nums[i%length]<=nums[stack.peek],直接压栈
            stack.push(i%length);
        }
        return result;
        
    }  
}
```