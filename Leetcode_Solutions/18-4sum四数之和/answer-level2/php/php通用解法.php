php K数之和通用解法
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[][]
     */
    function fourSum($nums, $target) {
		sort($nums);
        return $this->kSum($nums, $target, 4, 0);
    }
	
	function kSum($nums, $target, $k, $start){
		$res = [];
		if($k==2){
			$left = $start;
			$right = count($nums)-1;
			while($right>$left){
				if($nums[$right]+$nums[$left]==$target){
					$res[] = [$nums[$right],$nums[$left]];
					while($right>$left && $nums[$left] == $nums[$left+1]) $left++;
					while($right>$left && $nums[$right] == $nums[$right-1]) $right--;
					$left++;
					$right--;
				}else if($nums[$right]+$nums[$left]>$target){
					$right--;
				}else{
					$left++;
				}
			}
			return $res;
		}else if($k>2){
			for($i=$start;$i<count($nums)-$k+1;$i++){
				$temp = $this->kSum($nums, $target-$nums[$i], $k-1, $i+1);
				if(!empty($temp)){
					for($m=0;$m<count($temp);$m++){
						array_unshift($temp[$m],$nums[$i]);
					}
					$res = array_merge($res,$temp);
				}
				while($i<count($nums)-1&&$nums[$i]==$nums[$i+1]) $i++;
			}
			return $res;
		}
		return $res;
	}
}
```
