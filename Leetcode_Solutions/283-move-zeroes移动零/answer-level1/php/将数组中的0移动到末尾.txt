### 解题思路
遍历数组，引入一个非0的索引，将非0元素逐个替换到索引位置

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        $k = 0; // [0,k)中均为非0元素
        for($i=0;$i<count($nums);$i++){
            if($nums[$i]){
                $tmp = $nums[$i];
                $nums[$i] = $nums[$k];
                $nums[$k] = $tmp;
                $k++;
            }
        }

        return $nums;
    }
}
```