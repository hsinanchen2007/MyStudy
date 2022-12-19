### 解题思路
类似twoSum，我们可以用双指针来做这题。
1.首先，我们需要将原本的nums进行排序，让它从小到大排列，花费O(nlogn)时间。
2.无论如何，我们都需要将整个nums循环一次（i=0到nums.length-1)。对于任意i，我们设立一个左指针l，和一个右指针r。l=i+1，r=nums.length-1。每当这三个数相加的和大于0，代表r选的太大了，让r--；同理，如果相加的和小于0，代表l选的太小了，让l++；如果和等于0，则放入结果中。
3.同时，我们需要处理nums中相同的数字。对于i来说，当i>0且nums[i] == nums[i+1]的时候，也就是相邻两个i相同，我们需要舍弃靠左的i，选择最为靠右同值的i（只需要让i++即可）。当我们得到和等于0的时候，也需要对l和r做一次判断。如果l右边或者r左边有相同的数字，那么就忽略当前的l和r吧。

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        if (nums.length < 3){
            return res;
        }
        int l, r, sum;
        for (int i = 0; i < nums.length; i++){
            // 三个正数不可能等于0
            if (nums[i] > 0){
                return res;
            }
            // 忽略重复的i
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            l = i + 1;
            r = nums.length - 1;
            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0){
                    List<Integer> newLine = new ArrayList<>();
                    newLine.add(nums[i]);
                    newLine.add(nums[l]);
                    newLine.add(nums[r]);
                    res.add(newLine);
                    // 忽略重复的l
                    while (l < r && nums[l] == nums[l+1]){
                        l++;
                    }
                    // 忽略重复的r
                    while (l < r && nums[r] == nums[r-1]){
                        r--;
                    }
                    l++;
                    r--;
                } else if (sum > 0){
                    r--;
                } else {
                    l++;
                }   
            }
        }
        return res;
    }
}
```