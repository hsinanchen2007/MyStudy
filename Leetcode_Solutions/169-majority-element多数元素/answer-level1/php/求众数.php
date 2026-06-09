# 基础版

1. 新数组中的键是原数组中的值

```
    function majorityElement($nums) {
        $res = [];
        $count = count($nums)/2;
        if ($count < 1) {
            return $nums[0];
        }
        foreach ($nums as $val) {
            if (array_key_exists($val, $res)) {
                ++$res[$val];
                if ($res[$val] > $count) {
                    return $val;
                }
            } else {
                 $res[$val] = 1;
            }
        }
    }
```
