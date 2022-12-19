$copy_num = $nums;
        sort($nums);
        $index_start = 0;
        $index_end = count($nums)-1;
        $result = array();
        while($index_start < $index_end){
            if(($nums[$index_start] + $nums[$index_end]) === $target){
               break;
            }else if(($nums[$index_start] + $nums[$index_end]) < $target){
                $index_start++;
            }else if(($nums[$index_start] + $nums[$index_end]) > $target){
                $index_end--;
            }
        }
        array_search( $nums[$index_start], $copy_num);
        $result[0] = array_search( $nums[$index_start], $copy_num);
        for($i = 0; $i < count($copy_num); $i++){
            if($i != $result[0] && $copy_num[$i] ===  $nums[$index_end]){
                $result[1] = $i;
            }
        }
        return $result;