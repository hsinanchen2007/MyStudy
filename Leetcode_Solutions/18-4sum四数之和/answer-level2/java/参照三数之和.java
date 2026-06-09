### 解题思路
最基本的方法其实就是参照三数之和，a+b+c+d=target  ->> b+c+d=target-a
需要注意是判断几种情况，代码注释中会标出,其他的基本不变

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
List<List<Integer>> res = new ArrayList<List<Integer>>();
        int len = nums.length;
        if (len < 4 || nums == null){
            return res;
        }

        Arrays.sort(nums);
        for (int j = 0; j < len - 3; j++) {
//1.注意去重
            if (j>0 && nums[j]==nums[j-1]) continue;
            int tar = target - nums[j];
            for (int i = j+1; i < len; i++) {
//应为target不是0，所以加个tar >= 0条件
                if (tar >= 0 && nums[i]>tar) break;
//就是将nums划分成新数组nums[i:],所以去重条件由i > 0 改为i > j+1
                if (i > j+1 && nums[i] == nums[i-1]) continue;
                int L = i + 1;
                int R = len - 1;


                while (L < R){
                    int ans = nums[i]+nums[L]+nums[R];
                    if (ans == tar){
                        while (L < R && nums[L] == nums[L+1]) L++;
                        while (L < R && nums[R] == nums[R-1]) R--;
                        res.add(Arrays.asList(nums[j],nums[i],nums[L],nums[R]));
                        L++;
                        R--;
                    }else if (ans < tar) L++;
                    else R--;

                }
            }
        }


        return res;
    }
}
```