### 解题思路
解法一：暴力解法：这里要注意的地方是：先对原数组进行排序，便于后面的去重。（数组的位置不同也会被当成不同的数组）
解法二：排序+双指针法
### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);//排序的目的是让其有序的排列，使得相同的三个数组成的集合在该集合
                            //中排列的顺序相同，便于后续的去重。

        for(int i = 0; i < nums.length - 2; i++) {
            for (int j = i + 1; j < nums.length - 1; j++) {
                for(int k = j + 1; k < nums.length; k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        List<Integer> list= new ArrayList<>(3);
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[k]);
                        if(ans.indexOf(list) < 0){
                            ans.add(list);
                        }

                    }
                }
            }
        }
        return ans;

    }
}

//解法二：排序+双指针法
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for(int k = 0; k < nums.length - 2; k++) {
            if(nums[k] > 0) break;
            if(k > 0 && nums[k] == nums[k-1]) continue;//注意是k-1
            int i = k + 1,j = nums.length - 1;
            while(i < j){
                int s = nums[i] + nums[j] + nums[k];
                if(s > 0) {
                    while(i < j && nums[j] == nums[--j]);
                }else if(s < 0) {
                    while(i < j && nums[i] == nums[++i]);
                }else{
                    res.add(new ArrayList<Integer>(Arrays.asList(nums[k],nums[i],nums[j])));
                    while(i < j && nums[i] == nums[++i]);
                    while(i < j && nums[j] == nums[--j]);
                }
            }

        }
        return res;
    }
}


```