### 解题思路
误解：
一、最容易想到的就是，遍历数组，用in_array来过滤不在数组中的，这样如果重复元素过多，执行超时。
二、很多人提到的Hash，其实就是过滤重复元素，但是需要额外存储空间。

正解：
2次遍历数组，第一次遍历把访问过的元素做一个标记(**把数字映射到下标**，加一个负号)，因为是按照有序下标访问的，故而第二次遍历的时候如果数不为负，说明该数对应的下标没被访问，下标即消失的数字。

数组：[3, 3, 2, 1, 4, 5, 6, 4]
下标：[0, 1, 2, 3, 4, 5, 6, 7]

注意：访问过后为负，在次访问依旧是负。所以取数之前需要abs: $nums[abs($nums[$i]) - 1]


### 性能
执行用时 :148 ms, 在所有 PHP 提交中击败了55.56%的用户
内存消耗 :23.8 MB, 在所有 PHP 提交中击败了33.33%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function findDisappearedNumbers($nums) {
        $res = [];
        for ($i = 0; $i < count($nums); $i++) {
            $nums[abs($nums[$i]) - 1] = -abs($nums[abs($nums[$i]) - 1]);
        }

        for ($i = 0; $i < count($nums); $i++) {
            if ($nums[$i] > 0) $res[] = $i + 1;
        }

        return $res;
    }
}
```

参考：
[官方解答
](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/zhao-dao-suo-you-shu-zu-zhong-xiao-shi-de-shu-zi-2/)