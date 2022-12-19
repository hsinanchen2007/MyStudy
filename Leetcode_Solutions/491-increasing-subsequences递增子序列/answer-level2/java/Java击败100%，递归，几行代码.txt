### 解题思路
这个题用递归来做，大致有两种情况来考虑：

例子一：【4，6，7，7】中，如果我们此时已经递归到[4,6]了，下一位的话，我们可以在递归的同一层里选择index=2的数或index=3的数，但因为两个数相等，我们只选一个就好了，另一个跳过，所以我们只得到一遍[4,6,7]。但是为什么我们会[4,6,7,7]也是对的答案呢？因为此时的两个7不属于递归的同一层，index=3的数是index=2的数的下一层，分清递归的同一层级和不同层级很重要。

例子二：【4，6，7，7，4，4，4】中，当index=4时，nums[4]=4, 因为 nums[4]<nums[3],所以不是升序排列，与题目要求不符所以我们continue跳过。

大体上就是这两个要注意的点，有什么问题再留言吧。

### 代码

```java
class Solution {
    public static List<List<Integer>> findSubsequences(int[] nums) {

        List<List<Integer>> ans = new LinkedList<>();
        if(nums.length == 0) return ans;
        Stack<Integer> stack = new Stack<>();
        HashSet<Integer> Set = new HashSet<>();

        add(nums, ans, stack, 0, Set);
        return ans;
    }

    public static void add(int[] nums, List<List<Integer>> ans, Stack<Integer> stack, int start, HashSet<Integer> Set){
        if(stack.size()>1 && stack.size()<=nums.length) ans.add(new ArrayList<>(stack));

        for(int i=start; i<nums.length; i++){
            if(Set.contains(nums[i])) continue;  //对应例子1
            if(stack.size()>=1 && nums[i] < stack.peek()) continue; //对应例子2

            Set.add(nums[i]);
            stack.push(nums[i]);
            HashSet<Integer> new_Set = new HashSet<>();
            add(nums,ans,stack,i+1, new_Set);
            stack.pop();
        }
    }
}
```