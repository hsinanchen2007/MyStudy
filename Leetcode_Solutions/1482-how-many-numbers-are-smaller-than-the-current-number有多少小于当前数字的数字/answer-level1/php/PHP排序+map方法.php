# PHP排序+map方法
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function smallerNumbersThanCurrent($nums) {
        $newNums = $nums;
        sort($newNums);
        //var_dump($newNums);
        $re = [];
        $res =[];

        foreach ($newNums as $k1 => $v1) {
            if (!isset($res[$v1])) {
                $res[$v1] = $k1;
            }
        }

        foreach ($nums as $v) {
            $re[] =$res[$v]; 
        }

        return $re;
    }
}
```
