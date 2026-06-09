class Solution {

     /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    public function twoSum($nums, $target) {
        $rp = [];
        try {
             $numb = array_flip($nums);
         
             array_walk($nums,function($value, $key)use($target,$numb,&$rp){
                $diff = $target-$value;
                if (array_key_exists($diff,$numb)) {
                    if($key != $numb[$diff]) {
                         $rp =  [$key,$numb[$diff]];
                    throw new \Exception('数据为负');
                    }
                }
            });
        }catch (\Exception $e) {
            if($rp) {
                return $rp;
            } else {
                return [];
            }
        }
        
    }
}
$nums = [3,2,4];
$target = 6;
$so = new Solution();
$so->twoSum($nums, $target);


利用自带生成器yield应该还可优化