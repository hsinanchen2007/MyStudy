### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function countBinarySubstrings($s)
    {
        $s = str_split($s, 1);
        if (strlen($s <= 1)) {
            return 0;
        }

        $currentNum = $s[0];
        $count = $lastKey = $lastSeqLength = $currentSeqLength = 0;
        // 遍历到当前数字时，记录前面两段的长度，记录上一次数组发生变化的索引
        foreach ($s as $key => $num) {
            // 数字发生变化
            if ($num != $currentNum) {
                $currentSeqLength = $key - $lastKey;
                $count += min($lastSeqLength, $currentSeqLength);
                $currentNum = $num;
                $lastSeqLength = $currentSeqLength;
                $lastKey = $key;
            }
        }

        // 还要单独处理最后一段
        $currentSeqLength = count($s) - $lastKey;
        $count += min($lastSeqLength, $currentSeqLength);
        return $count;
    }
}
```