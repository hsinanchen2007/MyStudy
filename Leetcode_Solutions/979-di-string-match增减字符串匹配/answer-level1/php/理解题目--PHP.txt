### 解题思路


### 性能
执行用时 :28 ms, 在所有 PHP 提交中击败了38.46%的用户
内存消耗 :16.1 MB, 在所有 PHP 提交中击败了80.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return Integer[]
     */
    function diStringMatch($S) {
        $front = 0;
        $rear = strlen($S);

        $res = [];
        for ($i = 0; $i < strlen($S); $i++) {
            if ($S[$i] == 'I') $res[] = $front++;
            else $res[] = $rear--;
        }

        $res[] = $rear;

        return $res;
    }
}
```