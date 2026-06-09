### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function searchInsert($nums, $target) {
        $len = count($nums);

        if($len == 0){
            return 0;//判断是否为空数组
        }

        $k = array_search($target,$nums);//使用函数，判断数组是否存在该值
        if($k !== false){
            return $k;//如果存在，就返回该值的下标
        }

        for($i=0;$i<$len;$i++){
            if($nums[$i]>$target){
                return $i;//如果存在数值比该值打，就返回该数值的下标
            }
        }
        return $len;//否则，返回该长度。
    }
}
```