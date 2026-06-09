class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        $stem = [];
        for ($i = 0; $i < count($nums); $i++) {
            if (!isset($stem[$nums[$i]])) {
                $stem[$nums[$i]] = 1;
            }else {
                $stem[$nums[$i]] = $stem[$nums[$i]]+1;
            }
        }
        foreach ($stem as $key => $value) {
            if ($value == 1) {
                return $key;
            }
        }
    }
}