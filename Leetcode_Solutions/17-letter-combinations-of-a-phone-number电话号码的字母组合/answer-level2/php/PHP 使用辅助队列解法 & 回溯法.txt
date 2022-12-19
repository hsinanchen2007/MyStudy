### 辅助队列解法

```php
class Solution
{
    /**
     * @param String $digits
     * @return String[]
     */
    function letterCombinations($digits)
    {
        $map = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
        $digitCount = strlen($digits);
        if ($digitCount == 0) return [];

        $digits = str_split($digits, 1);        // 不要用回溯了，这就是个队列
        $queue = str_split($map[reset($digits)]);
        if ($digitCount == 1) return $queue;

        for ($i = 1; $i < $digitCount; ++$i) {
            $chars = str_split($map[$digits[$i]], 1);
            if (count($chars) == 0) continue;
            // 队列不为空，且队列内的元素长度小于当前遍历层数
            while (strlen(reset($queue)) < $i + 1) {
                $one = array_shift($queue);
                foreach ($chars as $char) {
                    $queue[] = $one . $char;
                }
            }
        }

        return $queue;
    }
}
```

### 回溯法

```php
class Solution
{
    protected $result = [];
    /**
     * @param String $digits
     * @return String[]
     */
    function letterCombinations($digits)
    {
        $map = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
        if (strlen($digits) == 0) return $this->result;
        $this->backtrack($digits, $map, [], 0);
        return $this->result;
    }

    private function backtrack($digits, $map, $path, $start)
    {
        if (count($path) == strlen($digits)) {
            $this->result[] = implode('', $path);
            return;
        }

        for ($i = $start; $i < strlen($digits); ++$i) {
            $chars = $map[substr($digits, $i, 1)];
            if (empty($chars)) continue;
            for ($j = 0; $j < strlen($chars); ++$j) {
                $char = substr($chars, $j, 1);
                $path[] = $char;
                $this->backtrack($digits, $map, $path, $i + 1);
                array_pop($path);
            }
        }
    }
}
```
