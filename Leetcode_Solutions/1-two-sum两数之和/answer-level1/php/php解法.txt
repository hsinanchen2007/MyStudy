```
    class Solution {

        /**
        * @param Integer[] $nums
        * @param Integer $target
        * @return Integer[]
        */
        function twoSum($nums, $target) {     
            $nums1 = [];
            foreach ($nums as $k => $v) {
                $difference = $target - $v;
                if (isset($nums1[$difference])) {
                    return [$k, $nums1[$difference]];
                } else {
                    $nums1[$v] = $k;
                }
            }
        }
    }
```
- 例：
- `$nums = [1,2,3];`
- `$target = 3;`
- 原本想通过`array_filp`反转键名键值，得到`$reversal=[1=>0,2=>1,3=>2]`
- 然后遍历`$reversal`,
- 用`isset($reversal[$target-$v])`判断对应的差值是否存在，
- 通过`array_keys`获取答案，然后发现如果`$nums`中有重复值`($nums=[1,1,2])`会丢失一个重复值
- 然后如果重复值刚好为所求答案时候就会异常。
- 手动遍历生成反转后的键名键值数组，
- 将已遍历的存到另一个数组里，拿到新值时判断其差值是否存在新数组里，
- 如果碰到重复值为所求答案，当遍历到第二个重复值时，第一个重复值放进了新数组，第二个还未放入，此时即可得出答案，不会丢失重复值；
- 如果两个重复值不是所求答案，那么即使答案需求重复值中的一个，那么丢失一个也不影响。

- 时间为16ms
- 内存15.9M，只超过了25%，不知道怎么才能少用内存。。。。
