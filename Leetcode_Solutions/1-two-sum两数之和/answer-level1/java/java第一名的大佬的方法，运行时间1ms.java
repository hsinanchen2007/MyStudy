1. 这里我谈谈对第一名的答案的理解（该代码不是我写的）：我认为使用的是一种类似于自己创建一个简单的哈希表的方法，indexArrays为那个哈希表，indexArrays中存放的其实是nums中元素的位置。而其中的diff & indexArrayMax我认为一是为了解决可能存在的负数的情况，二是为了解决nums中数值过大的情况，& indexArrayMax能够使nums中无论是什么数都能被约束到0-2047之间。总的来说，这样做是比java自带的hashmap要快一点，但是思路是一样的。
```
JAVA
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int indexArrayMax = 2047;
        int[] indexArrays = new int[indexArrayMax + 1];
        for (int i = 0; i < nums.length; i++) {
            int diff = target - nums[i];
            int index = diff & indexArrayMax;
            if (indexArrays[index] != 0) {
                return new int[] { indexArrays[index] - 1, i };
            }
            indexArrays[nums[i] & indexArrayMax] = i + 1;
        }
        throw new IllegalArgumentException("No two sum value");
    }
}

```
**复杂度分析：

时间复杂度：O(n)

空间复杂度：O(n)**

2. 如果使用HashMap,就和官方的方法几乎一致
```
JAVA
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            int left = target - nums[i];
            if(map.containsKey(left)){
                return new int[]{map.get(left),i};
            }
            map.put(nums[i],i);
            }
        throw new IllegalArgumentException("No two sum value");
    }
}
```

**复杂度分析：

时间复杂度：O(n)

空间复杂度：O(n)
**

**希望各位大佬点赞哈！！！**