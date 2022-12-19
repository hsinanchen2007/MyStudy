**题目**
给定一个整数 `数组 nums` 和一个 `目标值 target` ，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

**思路**
题目可以简化成在给定数组中查找两个值，满足某逻辑条件，在此题中，这个条件 `两数相加等于给定值`。创建一个散列表，存储 value => key 的映射，再遍历原数据，查找到需要的值 `target - value` 即可。需要注意的是，不能找到的数是自身对应的数据

**实现**

```php
class Solution {

    /**
     * hashMap 解法
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target)
    {
        $len = count($nums);
        $map = array();
        for ($i = 0; $i < $len; $i++) {
            $need = $target - $nums[$i];
            if (isset($hash[$need])) {
                return [$hash[$need], $i];
            }
            $hash[$nums[$i]] = $i;
        }

        return [-1, -1];
    }
}
```