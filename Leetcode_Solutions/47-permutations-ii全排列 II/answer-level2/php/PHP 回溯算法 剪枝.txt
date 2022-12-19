直接上代码，重点理解剪枝部分的处理

```php
class Solution
{
    protected $result = [];
    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function permuteUnique($nums)
    {
        if (empty($nums)) return [];
        sort($nums);
        $visited =
            array_fill(0, count($nums), false);
        $this->helper($nums, [], $visited);
        return $this->result;
    }

    private function helper($nums, $path, $visited)
    {
        if (count($path) == count($nums)) {
            $this->result[] = $path;
            return;
        }
        for ($i = 0; $i < count($nums); ++$i) {
            // 第一次剪枝，去掉已经访问过的
            if ($visited[$i]) continue;
            // 第二次剪枝，该元素与前一个元素相等，且前一个元素访问过
            if ($i > 0 && $visited[$i - 1] && $nums[$i] == $nums[$i - 1]) continue;
            $path[] = $nums[$i];
            $visited[$i] = true;
            $this->helper($nums, $path, $visited);
            array_pop($path);
            $visited[$i] = false;
        }
    }
}
```
