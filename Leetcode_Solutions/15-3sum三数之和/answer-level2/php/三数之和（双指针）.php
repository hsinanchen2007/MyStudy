# 基础版
感谢各位大佬的分享，研究了几位大佬写的题解，理解后用自己习惯的代码弄出来，学到了很多，很有意思的解法
在整个过程中，逻辑思路感觉还是比较清晰，但在具体写的时候，有些问题点没想通，出了几次幺蛾子，现在做一下记录。
问题以及优化：

    1. 循环遍历时，应该首先判断 `$nums[$last] == $nums[$last-1]`和`$nums[$last] == $nums[$last-1]`
    2. 当第一步完成后，再进行`--$last or ++$first`。如果顺序错误，当有多个相同值时，会出错
    3. 在php中，本题不适合用`do {} where ()`

```
function threeSum($nums) {
        sort($nums);
        $arr = [];
        $count = count($nums)-1;
        // 如果最大值与最小值是同号，则不存在相加小于等于0的情况，故直接返回即可。此处只能大于，不能大于等于
        if ($nums[0] * $nums[$count] > 0) {
           return $arr;
        }
        for ($i = 0; $i < $count-1; ++$i) {
            $first = $i+1;
            $last = $count;

            // 用当前值与上一个已经执行过的值比较，
            if ($i>0 && $nums[$i] == $nums[$i-1]) {
                continue;
            }
            while ($last > $first) {
                $res = $nums[$i] + $nums[$first] + $nums[$last];
                if ($res > 0) {
                // 这里顺序不能错，先去重，然后再向前进一步
                    while ($last > $first && $nums[$last] == $nums[$last-1]) {--$last;}
                    --$last;
                } elseif ($res < 0) {
                    while ($last > $first && $nums[$first] == $nums[$first+1]) {++$first;}
                    ++$first;
                } else {
                    $arr[] = [$nums[$first],$nums[$i],$nums[$last]];
                    while ($last > $first && $nums[$first] == $nums[$first+1]) {++$first;}
                    while ($last > $first && $nums[$last] == $nums[$last-1]) {--$last;}
                    --$last;
                    ++$first;
                }
            }
            
        }
        return $arr;
    }
```
