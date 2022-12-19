### 解题思路
求出最大值
维护单调递减栈
求栈剩余元素
    最大元素
    待循环遍历元素
### 代码

```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int [] output = new int[nums.length];
        if(nums==null || nums.length==0){
            return output;
        }
        int max = Arrays.stream(nums).max().getAsInt();
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<nums.length;i++){
            while (!stack.isEmpty()&&nums[i]>nums[stack.peek()]){
                int index = stack.pop();
                output[index] = nums[i];
            }
            stack.push(i);
        }
        while (!stack.isEmpty()){
            int top = stack.peek();
            if(nums[top]==max){
                output[stack.pop()]=-1;
            }else{
                for(int i=0;i<nums.length;i++) {
                    if (nums[i] > nums[top]) {
                        output[stack.pop()] = nums[i];
                        break;
                    }
                }
            }
        }
        return output;
    }
}
```