class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function containsDuplicate($nums) {
        if (count($nums) < 2) {
            return false;
        }else{
            sort($nums);
            for ($i = 0; $i < count($nums)-1; $i++) {
                if($nums[$i] == $nums[$i+1]){
                    return true;
                    exit;
                }else{
                    if ($i==count($nums)-2) {
                        return false;
                        exit;
                    }                    
                }
            }
        }        
    }
}