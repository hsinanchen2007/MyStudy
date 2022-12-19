### 解题思路
1. 使用辅助栈模拟出栈
2. 若最后栈为空，则符合要求

### 代码

```php

class Solution
{

    function validateStackSequences($pushed, $popped)
    {
        $stack = [];
        $j = 0;
        $cur = -1;

        for ($i = 0; $i < count($pushed); $i++) {

            array_push($stack, $pushed[$i]);
            $cur++;

          
            while ($stack[$cur] == $popped[$j]) {

                // 模拟出栈
                array_pop($stack);
                $cur--;
                $j++;

                // 指针越界 -> 辅助栈空 -> 全部模拟出完了
                if ($cur == -1) {
                    break;
                }
            }

        }

        return empty($stack);
    }
}
```