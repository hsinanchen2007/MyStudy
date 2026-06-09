### 解题思路
1、计算每一年人数的变化
    brith年份+1
    death的下一年-1
2、从1900年开始累积变化，即为当前年份的人数

### 代码

```php
class Solution {

    /**
     * 88ms 16.1MB
     * @param Integer[] $birth
     * @param Integer[] $death
     * @return Integer
     */
    function maxAliveYear($birth, $death) {
        $record = [];
        // death里2000年的 2000+1操作
        for ($i=1900;$i<=2001;$i++) {
            $record[$i] = 0;
        }
        foreach ($birth as $index => $year) {
            $record[$year]++;
            $record[$death[$index]+1]--;
        }
        $max = 0;
        $resultYear = 0;
        $cur = 0;
        for ($year=1900;$year<=2000;$year++) {
            // 累积每年的变化
            $cur += $record[$year];
            if ($cur > $max) {
                $max = $cur;
                $resultYear = $year;
            }
        }
        return $resultYear;
    }

    /**
     * 272ms 16.3MB
     * @param Integer[] $birth
     * @param Integer[] $death
     * @return Integer
     */
    function maxAliveYear2($birth, $death) {
        $record = [];
        for ($i=1900;$i<=2000;$i++) {
            $record[$i] = 0;
        }
        // 直接在活着的年份上+1
        foreach ($birth as $index => $start) {
            for ($i=$start;$i<=$death[$index];$i++) {
                $record[$i]++;
            }
        }
        $max = 0;
        $resultYear = 0;
        foreach ($record as $year => $count) {
            if ($count > $max) {
                $max = $count;
                $resultYear = $year;
            }
        }
        return $resultYear;
    }
}
```