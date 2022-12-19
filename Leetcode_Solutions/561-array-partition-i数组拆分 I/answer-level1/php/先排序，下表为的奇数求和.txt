     function arrayPairSum($nums) {
            sort($nums);
            $sum = 0;
            for($i=0;$i<count($nums);$i++){
                if((($i+1)%2)!=0){
                    $sum += $nums[$i];
                }
            }
            return $sum;
        }