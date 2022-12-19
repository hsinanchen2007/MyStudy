### 解题思路
此处撰写解题思路

### 代码
解1，使用指针碰到非零即交换
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        if(empty($nums)) return;
        $swap_index = 0;
        for($i=0;$i<count($nums);$i++){
            if($nums[$i]!=0){
                $temp = $nums[$i];
                $nums[$i] = $nums[$swap_index];
                $nums[$swap_index++] = $temp;
                /*
                $nums[$swap++] = $temp;
                同
                $nums[$swap] = $temp;
                $swap++;
                */
            }
        }
    }
}
```

解2，遇到0便删，在尾部推入0
```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        for($i=0;$i<count($nums);$i++){
            if($nums[$i] == 0){
                unset($nums[$i]);
                $nums[] = 0;
            }
        }

    }
}
```