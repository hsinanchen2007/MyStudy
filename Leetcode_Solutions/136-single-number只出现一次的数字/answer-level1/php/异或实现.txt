### 解题思路
0、最先想到的是遍历，把遍历过的元素存在$tmp中，检查当前遍历元素是否在$tmp中，不存在加入，存在删除。
1、异或

这里使用异或

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        $res = $nums[0];
        for ($i = 1; $i < count($nums); $i++) {
            $res = $res ^ $nums[$i];
        }

        return $res;
    }
}
```