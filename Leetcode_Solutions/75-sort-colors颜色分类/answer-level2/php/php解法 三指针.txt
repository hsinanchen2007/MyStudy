```
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function sortColors(&$nums) {
        $n = count($nums);
        $left = 0;
        $right = $n-1;
        $curr = 0;
        while($curr<=$right){
            if($nums[$curr]==0){
                $this->swap($nums,$curr,$left);
                $left++;
                $curr++;
            }else if($nums[$curr]==2){
                $this->swap($nums,$curr,$right);
                $right--;
                // 此处不需要curr++，因为有可能出现nums[curr]=2，nums[right]=0的情况
                // 换值后nums[curr]=0，nums[right]=2 还需要再次对curr与left换值
                // 如果curr++则跳过与left换值了
            }else{
                $curr++;
            }
        }
    }
    
    function swap(&$arr,$i,$j){
        $temp = $arr[$i];
        $arr[$i] = $arr[$j];
        $arr[$j] = $temp;
    }
}
```
