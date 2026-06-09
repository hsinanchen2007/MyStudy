class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */

    //[2,5,5,11,15,8]
     //10
    // function twoSum($nums, $target) {
    //     $res=[]; 
    //     foreach($nums as $k=>$v){
    //         $tmp=$nums;
    //         unset($tmp[$k]);
    //         $diff = $target-$v;
    //         if(array_search($diff,$tmp)){
    //             $serKay=array_search($diff,$tmp);
    //             unset($nums[$k],$nums[$serKay]);
    //             $res=array_merge($res,array($k,array_search($diff,$tmp)));
    //         }
    //     }
    //     return $res;
    // }

    function twoSum($nums, $target) {
        $res=[]; 
        foreach($nums as $k=>$v){
            $tmp=$nums;
            unset($tmp[$k]);
            $diff = $target-$v;
            if(array_search($diff,$tmp)){
                return array($k,array_search($diff,$tmp));
            }
        }
      
    }
}