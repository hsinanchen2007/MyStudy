### 解题思路
此处撰写解题思路
本题的思路其实是排序的一种变种，也即把两个数比较大小换成两个数字拼接后比较大小。其他的同正常排序一样。本题我采用了冒泡排序的方式，手写起来比较简单。大家也可以用其他的排序方式来实现
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return String
     */
    function minNumber($nums) {
        //模拟排序
        $len = count($nums);
        for ($i = 0; $i < $len; $i ++) {
            for ($j = $i + 1; $j < $len; $j ++) {
                if ((string)($nums[$i]) . (string)($nums[$j]) > (string)($nums[$j]) . (string)($nums[$i])) {
                    $tmp = $nums[$i];
                    $nums[$i] = $nums[$j];
                    $nums[$j] = $tmp;
                }
            }
        }
        return implode('', $nums);
    }
}
```