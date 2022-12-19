![2020022901.PNG](https://pic.leetcode-cn.com/78b0d87729772dd1ab334f463ce073f9b77baae26382f3b763af728a9cd93ac0-2020022901.PNG)
### 解题思路
给定的是数组,但该数组被声明是循环数组,
所以,在nums数组中,对于数nums[i],要将nums[i]与:1)索引大于i的数;2)索引小于i的数进行比较,从而尽可能找出第一个比nums[i]大的数;
声明数组out记录结果;
声明栈stack来记录数组中的数对应的索引;
1)将nums[i]与索引大于i的数进行比较:
遍历一遍数组,先将每个数nums[i]与其后面的数,即所有index>i的数进行比较;
遍历数组,若栈是空的,则将数组中的数直接入栈;
当栈非空时,以后每遍历一个数nums[i],将该数nums[i]与栈顶的数进行大小比较,
若该数nums[i]大于栈顶,则将栈顶元素弹出index=stack.poll(),且out[index]=nums[i];
若该数nums[i]小于栈顶元素,则将索引i直接入栈;
2)将nums[i]与索引小于i的数进行比较:
遍历完一遍数组后,再将栈中存留的元素索引index与数组中索引小于index的元素进行大小比较;
若能找出nums[i]大于nums[index]  (i<index)，则out[index]=nums[i];
否则,即找不出较大数时,out[index]=-1;
最后返回out;
### 代码

```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
    	int[] out = new int[nums.length];
    	Deque<Integer> stack = new LinkedList<>();
        //先将nums[i]与索引大于i的数进行大小比较,若存在较nums[i]大的数,则将栈中对应的索引元素出栈index=stack.poll(),并将out[index]=nums[i];
    	for(int i=0;i<nums.length;i++) {
    		if(stack.peek()==null||nums[stack.peek()]>=nums[i]) {
    			stack.push(i);
    		}else {
    			while(stack.peek()!=null&&nums[stack.peek()]<nums[i]) {
    				int index = stack.poll();
    				out[index] = nums[i];
    			}
    			if(stack.peek()==null||nums[stack.peek()]>=nums[i]) {
    				stack.push(i);
    			}
    		}
    	}
        //再将栈中存留的元素不断弹出Lastindex=stack.poll(),并将LastIndex对应数组中的数与数组中索引i<lastIndex的数进行大小比较,
        //若存在较nums[i]大的数,则将out[index]=nums[i];否则,nums[i]=-1;
    	boolean active = true;
    	while(stack.peek()!=null) {
    		int i = 0;
    		active = true;
    		int lastIndex = stack.poll();
    		while(i%nums.length!=lastIndex&&i<nums.length) {
    			if(nums[lastIndex]<nums[i%nums.length]) {
    				out[lastIndex]=nums[i%nums.length];
    				active=false;
    				break;
    			}
    			i++;
    		}
    		if(active) {
    			out[lastIndex]=-1;
    		}
    	}
    	return out;
    }
}
```