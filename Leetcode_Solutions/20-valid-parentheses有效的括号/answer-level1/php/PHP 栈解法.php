### 解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        if (empty($s)) {
            return true;
        }

        $length = strlen($s);
        // 奇数个字符，必然不符合
        if ($length % 2 == 1) {
            return false;
        }
        $map = [
            '(' => ')',
            '[' => ']',
            '{' => '}',
        ];
        $stack = new SplStack();
        for ($i = 0; $i < $length; ++$i) {
            $item = substr($s, $i, 1);
            switch ($item) {
                case '[':
                case '(':
                case '{':
                    $stack->push($map[$item]);
                    // 栈的深度大于字符串长度的一半，就可以提前结束
                    if ($stack->count() > $length / 2) {
                        return false;
                    }
                    break;
                case ']':
                case ')':
                case '}':
                    if ($stack->count() && $stack->top() == $item) {
                        $stack->pop();
                        break;
                    } else {
                        return false;
                    }
                default:
                    return false;
            }
        }

        return $stack->count() == 0;
    }
}
```

优化解法
```php
function isValid($s)
{
    $len = strlen($s);
    if ($len % 2 == 1) {
        return false;
    }

    $map = ['(' => ')', '[' => ']', '{' => '}'];
    $stack = new SplStack();
    for ($i = 0; $i < $len; ++$i) {
        $cur = substr($s, $i, 1);
        if (isset($map[$cur])) {
            $stack->push($map[$cur]);
            if ($stack->count() > $len / 2) {
                return false;
            }
        } else {
            if ($stack->count() && $stack->top() == $cur) {
                $stack->pop();
            } else {
                return false;
            }
        }
    }

    return $stack->count() == 0;
}
```
