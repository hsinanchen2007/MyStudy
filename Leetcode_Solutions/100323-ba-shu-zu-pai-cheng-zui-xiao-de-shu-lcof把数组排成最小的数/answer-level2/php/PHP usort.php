### 解题思路
此处撰写解题思路
另一种更优的方式是采用php自带的usort函数，实现匿名函数的自定义排序，其他的走快排的逻辑。代码如下更简单整洁
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return String
     */
    function minNumber($nums) {
        //模拟排序
        //var_dump('303' > '330');exit;
        usort($nums, function($a, $b) {
            $astr = (string)($a);
            $bstr = (string)($b);
            return ($astr . $bstr) > ($bstr . $astr);
        });
        return implode('', $nums);
    }
    
}
```