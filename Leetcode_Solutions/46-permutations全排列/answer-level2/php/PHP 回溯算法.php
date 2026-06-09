### 解题思路

典型的回溯算法，明确 路径、选择列表和结束条件。参考 labuladong 的题解。

### 代码

```php
class Solution {
    protected $result = [];
    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function permute($nums) {
        $count = count($nums);
        if ($count == 0) return $this->result; 
        $this->dfs($nums, 0, []);
        return $this->result;
    }

    private function dfs($nums, $depth, $path)
    {
        // terminator
        if ($depth == count($nums)) {
            $this->result[] = $path;
            return;
        }

        for ($i = 0; $i < count($nums); ++$i) {
            if (in_array($nums[$i], $path)) continue;
            $path[] = $nums[$i];
            $this->dfs($nums, $depth + 1, $path);
            // 回溯，恢复状态
            array_pop($path);
        }
    }
}
```