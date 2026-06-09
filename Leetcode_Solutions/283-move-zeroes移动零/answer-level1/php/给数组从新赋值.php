### 解题思路
此处撰写解题思路
相当于从数组的第一个元素开始，给数组从新赋值，首先定义数组下标变量从0开始，然后开始遍历数组，遇到第一个不为0的元素后，先把元素的值取出来赋值给数组对应的下标变量值，然后将数组原来位置的元素设置为0，然后数组下标变量自增
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        $noZero = 0;
        foreach($nums as $key => $val){
            if($val != 0){
                $nums[$key] = 0;
                $nums[$noZero] = $val;
                $noZero++;
            }
        }
    }
}
```