利用哈希字典快速查找,时间换取空间的做法，执行20ms

```php
class Solution
{

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    public function twoSum($nums, $target)
    {
        $two = $target / 2;
        $new = $nums;
        $n = array_search($two,$new);
        unset($new[$n]);
        if(($k = array_search($two,$new)) !== false){
            return [$n,$k];
        } else {
            $newarr = array_flip($nums);
            foreach ($nums as $k => $v){
                $complement = $target - $v;
                if(array_key_exists($complement,$newarr) && $complement != $two){
                    return [$k,$newarr[$complement]];
                }
            }
        }

    }
}
```