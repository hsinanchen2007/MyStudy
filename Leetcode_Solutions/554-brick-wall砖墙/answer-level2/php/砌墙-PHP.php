我不想多说。。。。。。。。。。。看代码吧。
```
class Solution
{

    /**
     * @param Integer[][] $wall
     * @return Integer
     */
    function leastBricks($wall)
    {
        $dp = array();
        $colLen = array_sum($wall[0]);
        foreach ($wall as $col) {
            $brickLen = 0;
            $i = 0;
            foreach ($col as $brick) {
                @$dp[$brickLen + $brick]++; //边缘加一
                $brickLen += $brick;//砖的起始长度变更
            }
        }
        unset($dp[$colLen]); //删除最后
 
        return count($wall) - @max($dp);
    }
}
```

