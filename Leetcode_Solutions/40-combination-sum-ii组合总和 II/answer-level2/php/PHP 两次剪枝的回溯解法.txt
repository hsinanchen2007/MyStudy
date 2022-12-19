直接上代码

```php
class Solution
{
    protected $result = [];
    /**
     * @param Integer[] $candidates
     * @param Integer $target
     * @return Integer[][]
     */
    function combinationSum2($candidates, $target)
    {
        if ($target <= 0) return [];
        sort($candidates);
        $this->helper($candidates, $target, [], 0);
        return $this->result;
    }

    private function helper($nums, $target, $path, $start)
    {
        if ($target < 0) return;
        if ($target == 0) {
            $this->result[] = $path;
            return;
        }

        for ($i = $start; $i < count($nums); ++$i) {
            // 第一次剪枝，因为数组排好序了，小的数字都得不到结果，大的数字就没有必要计算了
            if ($target - $nums[$i] < 0) break;
            // 第二次剪枝，如示例 [1,1,2,5,6]，遍历到第二个分支时，[1,2], [1,5], [1,6], [1,2,5], [1,2,6], [1,5,6] 
            // 这样的子树下的所有情况在第一次遍历时都已覆盖，无需再重复计算
            if ($i > $start) {
                if ($nums[$i] == $nums[$i - 1]) continue;
            }
            $path[] = $nums[$i];
            $this->helper($nums, $target - $nums[$i], $path, $i + 1);
            array_pop($path);
        }
    }
}
```
