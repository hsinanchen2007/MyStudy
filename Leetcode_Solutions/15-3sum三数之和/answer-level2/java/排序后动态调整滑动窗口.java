### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int len = nums.length;
        //特殊判断 空或不满3个元素均排除
        if(len < 3 || nums == null){return ans;}
        //数组进行排序
        Arrays.sort(nums);
        for (int i = 0; i< nums.length;i++){
            //因为是排序数组，所以元素大于0 后面的元素肯定大于0 跳出循环，数组不符合要求
            if (nums[i] >0){break;}
            //因为进行左边重复值判断，避免i越界，加上i>0判断，同时跳出本次循环保证去重
            if ( i >0 && nums[i] == nums[i-1]){continue;}
            //初始化滑动窗口为 [i,L.....R]
            int L = i +1;
            int R = len -1;
            //当L<R时 执行求sum运算，否则即为没有合适的组合list
            while (L < R){
                int sum = nums[i] + nums[L] + nums[R];
                //如果求和结果为0，表示命中，添加到ans 结果列表中
                if(sum == 0){
                    ans.add(Arrays.asList(nums[i],nums[L], nums[R]));
                    //通过左边 和右边去重，获取下一个可能出现的滑动窗口
                    while(L<R && nums[L] == nums[L+1]) L++;
                    while(L<R && nums[R] == nums[R-1]) R--;
                    L++;
                    R--;
                }
                //如果sum不为0，会分为小于0 或大于0 两种情况，调整L和R的位置
                else if(sum < 0 ){L++;}
                else if (sum >0){R--;}
            }
        }
        return ans;
    }
}
```