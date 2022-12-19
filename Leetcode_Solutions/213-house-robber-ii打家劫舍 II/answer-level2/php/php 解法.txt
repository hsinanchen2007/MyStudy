动态规划方法helper(),[使用的是《198题打家劫舍》的方法](https://leetcode-cn.com/problems/house-robber/solution/php-jie-fa-dong-tai-gui-hua-by-andfly-10/)
分两种情况
第一种情况，nums索引取值范围[0,n-2]（即不包含最后一个元素） 
第二种情况，nums索引取值范围[1,n-1] (即不包含第一个元素)
返回两种情况中的较大者
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function rob($nums) {
        $n = count($nums);
        if($n==0) return 0;
        if($n==1) return $nums[0];
        return max($this->helper(array_slice($nums,0,$n-1)),$this->helper(array_slice($nums,1)));
    }

    function helper($nums) {
        if(empty($nums)) return 0;
        $dp[0] = $nums[0];
        $dp[1] = max($nums[0],$nums[1]);
        for($i=2;$i<count($nums);$i++){
            $dp[$i] = max($nums[$i]+$dp[$i-2],$dp[$i-1]);
        }
        return $dp[count($nums)-1];
    }
}
```
