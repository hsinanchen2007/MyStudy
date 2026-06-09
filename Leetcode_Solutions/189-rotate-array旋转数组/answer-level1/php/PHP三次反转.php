### 解题思路
1. 全部翻转
2. K位置之前翻转
3. K位置之后反转
注: 判断K是否超过数组总长度

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return NULL
     */
    function rotate(&$nums, $k) {
        $count = count($nums);
        $k = $k % $count;
        $this->reverse($nums, 0, $count-1);
        $this->reverse($nums, $k, $count-1);
        $this->reverse($nums, 0, $k-1);
    }

    function reverse(&$nums, $s, $e){
        while ($s<$e) {
            $tmp = $nums[$s];
            $nums[$s] = $nums[$e];
            $nums[$e] = $tmp;
            $s++;
            $e--;
        }
    }
}
```