给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
示例 2:

输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。

```java
/*
https://www.youtube.com/watch?v=j-BUX8_1tBY
time: o(n)
space: o(1)
*/
class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new ArrayList<>();
        if(nums == null || nums.length == 0){
            return res;
        }
        int start = 0;
        for(int i=1; i<nums.length; i++){
          	//如果前一个元素不等于当前的元素减1，说明出现了间隔（gap）
            if(nums[i-1] != nums[i]-1){
              	//如果左边和右边界相等，只需要添加一个就行
                if(start == i-1){
                    res.add(nums[start] + "");
                }else{
                  	//否则添加两个
                    res.add(nums[start] + "->" + nums[i-1]);
                }
              	//当前的区间添加完了[start, i-1], start更新到下一个区间
                start = i;
            }
        }
      	//如果左边界是最后一个元素
        if(start == nums.length-1){
            res.add(nums[start] + "");
        }else{
          	//左边界不是最后一个元素，说明区间是[start, 尾末]
            res.add(nums[start] + "->" + nums[nums.length-1]);
        }
        return res;
    }
}
```

