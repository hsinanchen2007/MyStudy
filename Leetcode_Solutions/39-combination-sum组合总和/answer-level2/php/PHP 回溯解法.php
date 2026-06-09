典型的回溯算法题，可以小样本量在纸上画出递归树。
![111.png](https://pic.leetcode-cn.com/acc478c9f2eadfe4aadb46bef583131e51ea4c556aadf6add3565875b882bdbd-111.png)

```php
class Solution
{
    protected $result = [];
    /**
     * @param Integer[] $candidates
     * @param Integer $target
     * @return Integer[][]
     */
    function combinationSum($candidates, $target)
    {
        if ($target <= 0) return [];
        sort($candidates);
        $this->combine($candidates, $target, [], 0);
        return $this->result;
    }

    private function combine($nums, $target, $list, $start)
    {
        // terminator
        if ($target < 0) return;
        if ($target == 0) {
            $this->result[] = $list;
            return;
        }

        for ($i = $start; $i < count($nums); ++$i) {
            // 由于数字是排好序的，所以可以进行剪枝
            if ($target - $nums[$i] < 0) break;
            $list[] = $nums[$i];
            // 数字可重复使用
            $this->combine($nums, $target - $nums[$i], $list, $i);
            // 回溯
            array_pop($list);
        }
    }
}
```
