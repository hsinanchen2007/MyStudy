直接上代码，重点是理解剪枝的操作

```php
class Solution
{
    protected $result = [];
    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function subsetsWithDup($nums)
    {
        if (empty($nums)) return [[]];
        sort($nums);
        $used = array_fill(0, count($nums), false);
        $this->ss($nums, [], 0, $used);
        $this->result[] = [];
        return $this->result;
    }

    private function ss($nums, $path, $start, $used)
    {
        if (count($path) == count($nums)) {
            return;
        }

        for ($i = $start; $i < count($nums); ++$i) {
            if ($i > 0 && $nums[$i] == $nums[$i - 1] && !$used[$i - 1]) continue;
            $path[] = $nums[$i];
            $used[$i] = true;
            $this->result[] = $path;
            $this->ss($nums, $path, $i + 1, $used);
            array_pop($path);
            $used[$i] = false;
        }
    }
}
```
