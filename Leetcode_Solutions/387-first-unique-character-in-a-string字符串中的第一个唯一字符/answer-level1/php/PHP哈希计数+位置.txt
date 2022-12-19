- 建立哈希表并且计数和记录位置
- 判断出现一次并返回位置
```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function firstUniqChar($s) {
        if (empty($s)) {
            return -1;
        }
        $hash = [];
        $count = strlen($s);
        for ($i=0;$i<$count;$i++) {
            if (!isset($hash[$s[$i]])) {
                $hash[$s[$i]]['total'] = 1;
                $hash[$s[$i]]['index'] = $i;
            } else {
                $hash[$s[$i]]['total'] += 1;
            }
        }
        foreach ($hash as $value) {
            if ($value['total']==1) {
                return $value['index'];
            }
        }
        return -1;
    }
}
```
