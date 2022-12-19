每次插入索引i时把数组从i处分割成左右两部分，然后再把该索引对应的数 与左右两部分合并

    /**
     * @param Integer[] $nums
     * @param Integer[] $index
     * @return Integer[]
     */
    function createTargetArray($nums, $index) {
        $target = [];
        foreach($index as $i){
            if(isset($target[$i])){
                $left = array_slice($target, 0, $i);
                $right = array_slice($target,$i);
                $target = array_merge($left,[array_shift($nums)], $right);
            }else{
                $target[] = array_shift($nums);
            }
        }
        
        return $target;
    }