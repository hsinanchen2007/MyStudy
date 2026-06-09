### 解题思路
此处撰写解题思路
本题一开始的思路的即为暴力法，遍历数组，判断为偶数则在数组后面添加，若为奇数则添加在前面。php自带的函数不难实现；但是提交后提示超时。
题解二：双指针法，即为两头指针，分为以下四种情况
1. 左右两边都是偶数，则右边指针左移
2. 左边是奇数，右边是偶数，则左边右移，右边左移
3. 左边是偶数，右边是奇数，则左右交换后双双移动指针
4. 左右都是奇数，则左边右移。
代码如下
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function exchange($nums) {
        $start = 0;
        $end = count($nums) - 1;
        while ($start < $end) {
            if (($nums[$start] & 1) == 0 && ($nums[$end] & 1) == 0) {
                $end --;
            } elseif (($nums[$start] & 1) == 1 && ($nums[$end] & 1) == 0) {
                $start ++;
                $end --;
            } elseif (($nums[$start] & 1) == 0 && ($nums[$end] & 1) == 1) {
                $tmp = $nums[$start];
                $nums[$start] = $nums[$end];
                $nums[$end] = $tmp;
                $start ++;
                $end --;
            } else {
                $start ++;
            }
        }
        return $nums;
    }
}
```