[78题解法](https://leetcode-cn.com/problems/subsets/solution/php-jie-fa-liang-chong-hui-su-jie-fa-by-andfly/)
本题在78题解法上最后加上一行代码（用于二维数组去重），即可。
```
function subsetsWithDup($nums) {
    $n = count($nums);
    if($n == 0) return [[]];
    sort($nums);
    $dp[1] = [[],[$nums[0]]];
    for($i=2;$i<=$n;$i++){
        $tmpall = [];
        for($j=0;$j<count($dp[$i-1]);$j++){
            $tmp = $dp[$i-1][$j];
            array_push($tmp,$nums[$i-1]);
            array_push($tmpall,$tmp);
        }
        $dp[$i] = array_merge($dp[$i-1],$tmpall);
    }
    return array_unique($dp[$n], SORT_REGULAR);
}
```
