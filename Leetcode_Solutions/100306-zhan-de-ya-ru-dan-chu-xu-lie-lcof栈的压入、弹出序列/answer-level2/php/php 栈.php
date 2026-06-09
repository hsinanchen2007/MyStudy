### 解题思路
此处撰写解题思路
本题的思路比较清晰，即声明一个栈arr来模拟popped的出栈行为，遍历数组popped分为以下两种情况
1. 元素不存在arr中时，将pushed中的元素入栈
2. 当元素存在arr中时，arr出栈，判断出栈元素与该元素是否相同

### 代码

```php
class Solution {

    /**
     * @param Integer[] $pushed
     * @param Integer[] $popped
     * @return Boolean
     */
    function validateStackSequences($pushed, $popped) {
        $arr = [];
        foreach ($popped as $value) {
            if ($x = array_search($value, $arr) === false) {
                foreach ($pushed as $key => $value2) {
                    $arr[] = $value2;
                    unset($pushed[$key]);
                    if ($value2 == $value) {
                        break;
                    }
                }
                array_pop($arr);
            } else {
                if (array_pop($arr) != $value) {
                    return false;
                } 
            }
        }
        return true;
    }
}
```