![image.png](https://pic.leetcode-cn.com/8da6eac8dbf05fe69074e567daac932bfd9019ef781889b9d4d612f63cca718d-image.png)
哈希表支持随机查找,时间复杂度为O(n)
但是需要额外存储空间.
```
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function repeatedNTimes($A) {
        if (empty($A)) {
            return false;
        }
        # 数组的hash table
        $hash = [];
        $count = count($A);
        for ($i=0;$i<$count;$i++) {
            if (!isset($hash[$A[$i]])) {
                $hash[$A[$i]] = 1;
            } else {
                $hash[$A[$i]] += 1;
            }
            # 如果找到重复值,则直接返回即可
            if (isset($hash[$A[$i]]) && $hash[$A[$i]] > 1) {
                return $A[$i];
            }
        }
        return false;
    }
}
```
