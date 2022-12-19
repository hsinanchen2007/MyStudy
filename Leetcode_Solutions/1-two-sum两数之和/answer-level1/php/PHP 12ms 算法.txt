class Solution {

    function twoSum($nums, $target) {
        $numsNum=count($nums);
        $numsFlip=array_flip($nums);
        foreach($nums as $key => $row){
            $diff=$target-$row;

            if(isset($numsFlip[$diff]) && $key!=$numsFlip[$diff]){
                return [$key,$numsFlip[$diff]];
            }
            
        }
    }
}

