### 解题思路
1. 构建左右括号映射关系
2. 分割入参字符串成数组
3. 初始化临时栈结构
4. 遍历入参数组，字符为左符号的，压入临时栈内；字符为右符号的，从临时栈中弹出一个字符，判断是否一致，不一致则返回false
5. 最终临时栈为空，返回true，否则返回false

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $mapArr = ['(' => ')', '[' => ']', '{' => '}'];

        $sArr = str_split($s, 1);

        $tmp = [];
        foreach ($sArr as $v) {
            if (in_array($v, array_keys($mapArr))) array_unshift($tmp, $v);
            if (in_array($v, array_values($mapArr))) {
                $openStr = array_shift($tmp);
                if ($v != $mapArr[$openStr]) return false;
            }
        }
        if (!$tmp) return true;
        return false;
    }
}
```