基本解法: 此时假设有且只有一个众数
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        $ret = reset($nums);
        $middleValue = (int)(count($nums) / 2);
        $temp = [];
        foreach ($nums as $item) {
            if (isset($temp[$item])) {
                $temp[$item]++;
                if ($temp[$item] > $middleValue) $ret = $item;
            }
            else $temp[$item] = 1;
        }
        return $ret;
    }
}

但我感觉一组数据中应该不只有一个众数的,所以当众数不只有一个时
class Solution
{

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function majorityElement($nums)
    {
        $ret = [];
        $middleValue = (int)(count($nums) / 2);
        $temp = [];
        foreach ($nums as $item) {
            if (isset($temp[$item])) {
                if ($temp[$item] > $middleValue) continue;
                $temp[$item]++;
                if ($temp[$item] > $middleValue) $ret[] = $item;
            } else $temp[$item] = 1;
        }
        return $ret;
    }
}