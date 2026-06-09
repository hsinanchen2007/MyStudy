利用array_keys的第二个参数进行 \$target-\$num[\$i] 的减数进行查找，如果找到会返回一个数组，但是如果有两个值就需要判断该值相对于本身的大小问题
 
时间208ms

希望有大佬能说下PHP的大佬的终极解法

我知道大佬们神仙解法   PHP 如何12.5ms 之内解出的  

```php
/*
 * @lc app=leetcode.cn id=1 lang=php
 *
 * [1] 两数之和
 */
class Solution
{

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    public function twoSum($nums, $target)
    {
        $temps = count($nums);
        for ($i=0;$i<$temps;$i++) {
            $temp = array_keys($nums,($target-$nums[$i]));
            if(is_array($temp)){
                $m = count($temp);
                $j = $temp[($m-1)];
                if($j>$i)
                    return array($i,$j);                 
            }
        }
    }
}
```