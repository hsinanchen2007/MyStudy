1. 数组中的每一个元素只有“存在”和“不存在”两种状态，由此可展开一棵二叉状态树，算法如下：
```
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> list = new LinkedList<>();
        backtrack(nums, 0, new LinkedList<>(), list);
        return list;
    }

    public void backtrack(int[] nums, int beginIndex, LinkedList<Integer> linkedList, List<List<Integer>> list) {
        if (beginIndex >= nums.length) {
            list.add(new LinkedList<>(linkedList));
            return;
        }
        linkedList.add(nums[beginIndex]);
        backtrack(nums, beginIndex + 1, linkedList, list);
        linkedList.removeLast();
        backtrack(nums, beginIndex + 1, linkedList, list);
    }
}
```

2. 假设数组包含N个元素，分别考虑每一个元素（注意考虑空元素的情况）作为组成子集元素的起点，由此展开一棵多叉状态树，算法如下：
```
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> list = new LinkedList<>();
        backtrack(nums, 0, new LinkedList<>(), list);
        return list;
    }

    public void backtrack(int[] nums, int beginIndex, LinkedList<Integer> linkedList, List<List<Integer>> list) {
        if (beginIndex > nums.length) {
            list.add(new LinkedList<>(linkedList));
            return;
        }
        for (int i = beginIndex; i <= nums.length; i++) {
            if (i < nums.length) {
                linkedList.add(nums[i]);
            }
            backtrack(nums, i + 1, linkedList, list);
            if (i < nums.length) {
                linkedList.removeLast();
            }
        }
    }
}
```

