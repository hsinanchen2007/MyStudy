### 解题思路
此处撰写解题思路
先反转数组是为了后面找key方便，然后结果和当前数相减得出a，用in_array()去数组里找a，如果有，则取出key来就行了。
### 代码

```php
class Solution
{

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target)
    {
        $numsNew = array_flip( $nums );

        foreach ($nums as $key => $num) {
            $findValue = $target - $num;
            /*echo $findValue;
            echo $num;
            print_r($nums);
            echo '<hr>';*/
            //echo '<br>';
            unset($nums[$key]);
            if( in_array( $findValue, $nums ) )
            {
                return [$key, $numsNew[$findValue]];
            }else
            {
                $nums[$key] = $num;
            }
        }
    }
}
```