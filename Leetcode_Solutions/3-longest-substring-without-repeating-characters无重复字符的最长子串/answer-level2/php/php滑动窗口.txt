### 解题思路
滑动窗口，遍历字符串，如果不在窗口数组中，则加入窗口数组尾部。如果在窗口数组中，则从左剔除窗口数组中的元素，直至当前遍历到的元素不在窗口数组中为止，然后将当前字符加入窗口数组尾部。

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($str) {
        // 校验

        // 滑动窗口
        $window = array();
        $maxLen = 0;

        for($i = 0; $i < strlen($str); $i++){
            while (in_array($str[$i], $window)) {
                array_shift($window);
            }
            $window[] = $str[$i];
            $maxLen = count($window) > $maxLen ? count($window) :$maxLen;
        }

        return $maxLen;
    }
}
```