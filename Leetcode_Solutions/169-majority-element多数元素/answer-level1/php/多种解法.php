### 解题思路
详情如下
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        //Solution #1
        // $elements = array_count_values($nums); //返回每个值出现的次数
        // return array_search(max($elements), $elements);//找出最多出现数字

        //Solution #2
        sort($nums);
        //the number in the middle will always be the dominating number in the ascending array
        return $nums[floor(count($nums) / 2)];

        //Slution #3
        // $stack = [];
        // foreach ($nums as $num) {
        //     if (empty($stack) || end($stack) == $num) {//栈为空或者最后一个元素为当前元素则往栈里添加
        //         $stack[] = $num;
        //     } else {//不一样就删最后一个
        //         array_pop($stack);
        //     }
        // }

        //最终栈里有且应只有同样的某个数字
        // return end($stack);

    }
}
```