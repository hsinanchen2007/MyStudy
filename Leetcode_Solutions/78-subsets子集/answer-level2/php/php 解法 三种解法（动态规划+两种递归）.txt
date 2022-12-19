动态规划解法：
```
function subsets($nums) {
    $n = count($nums);
    if($n == 0) return [[]];
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
    return $dp[$n];
}
```


回溯解法1：
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function subsets($nums) {
        if(count($nums)==0) return [];
        $ans = [[],[$nums[0]]];
        $this->backtrack(1,$nums,$ans);
        return $ans;
    }
    
    function backtrack($n,$nums,&$ans){
        if($n==count($nums)){
            return ;
        }
        $tmpall = [];
        for($i=0;$i<count($ans);$i++){
            $tmp = $ans[$i];
            array_push($tmp,$nums[$n]);
            $tmpall[] = $tmp;
        }
        $ans = array_merge($ans,$tmpall);
        $this->backtrack($n+1,$nums,$ans);
    }
}
```

回溯解法2：
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function subsets($nums) {
        if(count($nums)==0) return [];
        $ans = [];
        $this->backtrack(0,$nums,[],$ans);
        return $ans;
    }
    
    function backtrack($i,$nums,$tmp,&$ans){
        $ans[] = $tmp;
        for($j = $i; $j < count($nums); $j++){
            array_push($tmp,$nums[$j]);
            $this->backtrack($j+1,$nums,$tmp,$ans);
            array_pop($tmp);
        }
    }
}
```