
算法思路：生成一个和原数组相同大小的数组，然后让这个辅助数组（按照顺序）保存原来数组各个元素出现的次数，这里举例来说明下。

`nums = [1,2,2,4],辅助数组[0,0,0,0],并遍历nums`
`当访问第一个元素时候，辅助数组变成[1,0,0,0]`
`当访问第二个元素时候，辅助数组变成[1,1,0,1]`
`当访问第三个元素时候，辅助数组变成[1,2,0,0]`
`当访问最后一个元素，辅助数组变成了[1,2,0,1]`
`可见，我们只需要计算出这个数值为2的数字，即为重复的数字，那么数值为0的即为没有出现的数字`

`这个数字的计算：数字 = 索引值+1`


```Java []
class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] arr = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            arr[nums[i]-1] += 1;
        }
        
        int[] ans = {-1,-1};
        for (int j = 0; j < arr.length; j++) {
            if (arr[j] == 2) ans[0] = j+1 ;
            else if (arr[j] == 0) ans[1] = j+1 ;
        }
        return ans;
    }
}
```
```Python []
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        arr = [0]*len(nums)
        for num in nums:
            arr[num - 1] += 1
        return [arr.index(2),arr.index(0)]
```

觉得还行的话，留下您的赞（手动比心）。
