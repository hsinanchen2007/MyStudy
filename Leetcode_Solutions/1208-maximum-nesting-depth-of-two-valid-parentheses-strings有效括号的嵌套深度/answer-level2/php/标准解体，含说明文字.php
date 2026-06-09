### 解题思路
1、模拟一个栈 ans、初始化深度为-1（为啥-1而不是0？ 因为题目要求第一个括号是0，方便后面++操作）
2、将字符串通过split函数格式化成数组
3、循环字符串数组

### 代码

```php
class Solution {

    /**
     * @param String $seq
     * @return Integer[]
     */
    function maxDepthAfterSplit($seq) {
        $ans = [];
        $deep = -1;
        $seq = str_split($seq);
        foreach ($seq as $str) {
            if ($str === '(') {
                $deep++;
                array_push($ans, $deep%2);
            }
            if ($str === ')') {
                array_push($ans, $deep%2);
                $deep--;
            }
        }

        return $ans;
    }
}
```