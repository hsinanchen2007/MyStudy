### 解题思路
1. 遍历数组，遇到为零的元素，unset，并计数count；
2. 在unset掉0元素的数组基础上，追加count个0；

### 代码

```php
class Solution {
    // 解法1
    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        $cnt = 0;
        foreach($nums as $k => $num) {
            if($num === 0) {
                $cnt++;
                unset($nums[$k]);
            }
        }
        while($cnt) {
            array_push($nums, 0);
            $cnt--;
        }
        return $nums;
    }
}
```