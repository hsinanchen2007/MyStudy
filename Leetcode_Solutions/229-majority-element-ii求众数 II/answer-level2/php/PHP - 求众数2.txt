class Solution
{

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function majorityElement($nums)
    {
        $ret = [];
        $middleValue = (int)(count($nums) / 3);
        $temp = [];
        foreach ($nums as $item) {
            if (isset($temp[$item])) {
                if ($temp[$item] > $middleValue) continue;
                $temp[$item]++;
            } else $temp[$item] = 1;
            if ($temp[$item] > $middleValue) $ret[] = $item;
        }
        return $ret;
    }
}