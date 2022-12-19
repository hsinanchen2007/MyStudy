### 解题思路
    这道题还是一个单调栈的应用问题，我们可以开辟一个栈，每当遍历到一个新的元素时，就把所有比它小的元素都出栈。并且将将这些元素的下一个最大元素记为该元素。本题中由于数组是循环数组，因此要遍历两遍。

### 代码

```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        int [] res=new int[n];
        Arrays.fill(res,-1);
        Stack <Integer> stack=new Stack<>();
        for(int i=0;i<n*2;i++)
        {
            int num=nums[i%n];
            while(!stack.isEmpty()&&num>nums[stack.peek()])
                res[stack.pop()]=num;
            if(i<n)
                stack.add(i);
        }
        return res;
    }
}
```