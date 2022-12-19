### 解题思路
1. 简历hash表统计次数
2. 排序
3. 取出前k个

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer[]
     */
    function topKFrequent($nums, $k) {
        $hash = $out = [];
        $count = count($nums);
        for ($i=0;$i<$count;$i++) {
            if (isset($hash[$nums[$i]])) {
                $hash[$nums[$i]] += 1;
            } else {
                $hash[$nums[$i]] = 1;
            }
        }
        arsort($hash);
        $t = 0;
        foreach($hash as $key=>$v) {
            if ($t==$k) {
                break;
            }
            $out[] = $key;
            $t++;
        }
        return $out;
    }
}
```