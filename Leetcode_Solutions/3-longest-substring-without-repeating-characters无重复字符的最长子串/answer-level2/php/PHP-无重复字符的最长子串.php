### 解题思路
1 需要一个数组存储当前不重复的子序列，一个存储每个子序列的大小。
2 注意遇到重复字符时，子序列数组要从0删到重复字符的位置。
3 循环完毕后，最后一次的子序列大小不要忘记记录进$num中

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        if (strlen($s) == 0) return 0;
        $arr = str_split($s); // 把字符串切割为数组
        $subArr = [];
        $num = [];

        foreach ($arr as $k => $v) {
            if (in_array($v, $subArr)) { // 如果该字符存在$subArr中，则说明重复
                $num[] = count($subArr); // 把当前子序列的长度存储起来
                array_splice($subArr, 0, array_search($v, $subArr)+1); // 从 0 开始清空 至 子序列数组中对应重复的字符开始位置
            }
            $subArr[] = $v; // 将该字符存入到子序列数组中
        }
        // 最后一次的数组长度也需要记录
        $num[] = count($subArr);
        return max($num);
    }
}
```