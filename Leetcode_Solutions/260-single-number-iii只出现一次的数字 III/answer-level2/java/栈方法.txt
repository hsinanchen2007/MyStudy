在不考虑题目时间空间要求，仅考虑解决问题的情况下， 可以将数组排序后操作，首先将第一个数字入栈，之后遍历数组，在栈顶元素与当前元素相同时出栈，否则将该元素入栈
最终栈中将剩下两个单独的数字，即完成解答，解法与括号匹配的问题类似， 但题目要求了线性时间复杂度和常数空间，本答案则不符合要求。


class Solution 
{
    public int[] singleNumber(int[] nums)
    {
        int count1=0;
        int count2=0;
        Arrays.sort(nums);
        Stack <Integer>stack = new Stack();
        stack.push(nums[0]);
        for(int i=1;i<nums.length;i++)
        {
            if(!stack.isEmpty()&&nums[i]==stack.peek())
            {
                stack.pop();
            }
            else
            {
                stack.push(nums[i]);
            }
        }
        int a[] = new int[2];
        a[0]=stack.peek();
        stack.pop();
        a[1]=stack.peek();
        return a;
    }
}
