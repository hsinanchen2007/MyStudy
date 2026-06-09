function rotate(&$nums,$k) {
        if(count($nums)==1){
            $nums = $nums;
        }else {
            $j = 0;
            while($j < $k){
                array_unshift($nums,$nums[count($nums)-1]);
                unset($nums[count($nums)-1]);
                $j++;
            }
        }
        return $nums;
    }