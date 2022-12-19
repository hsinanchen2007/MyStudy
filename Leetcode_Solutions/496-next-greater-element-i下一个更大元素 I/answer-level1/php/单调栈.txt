### 解题思路
算法：
0、定义一个栈
1、遍历nums2, 如果栈不为空并且栈顶元素小于当前元素, 存入map, key = 栈顶元素，value = 当前元素;
2、一直检查栈顶直到，栈顶元素大于等于当前元素。
3、当前元素压栈。
4、遍历nums1, 在map中取对应的值，不存在记-1
5、返回结果

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function nextGreaterElement($nums1, $nums2) {
        $stack = [];
        for ($i = 0; $i < count($nums2); $i++) {
            while (!empty($stack) && end($stack) < $nums2[$i]) {
                $map[array_pop($stack)] = $nums2[$i];
            }
            array_push($stack, $nums2[$i]);
        }

        $res = [];
        for ($j = 0; $j < count($nums1); $j++) {
            if (isset($map[$nums1[$j]])) {
                $res[] = $map[$nums1[$j]];
            } else {
                $res[] = -1;
            }
        }

        return $res;
    }
}
```