### 解题思路
重复项的思路很简单，数组的key是一定唯一的，所以将数组翻转一次，重复的Key自然就被代替掉了，然后再翻转回来。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $nums = array_flip(array_flip($nums));
    }
}
```