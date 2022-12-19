### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @param Integer $target
     * @return Boolean
     */
    function findNumberIn2DArray($matrix, $target) {
        //第一种，暴力，两次循环，n*m
        //第二种，从右上角开始
        $i=0;
        $row=count($matrix);//行
        $column=count($matrix[0]);//列
        $j=$column-1;
        while($i<$row && $j>=0){
            if($matrix[$i][$j]==$target){
                return true;
            }
            if($matrix[$i][$j]<$target){
                $i++;//向下
            }else{
                $j--;//向下
            }

        }
        return false;
    }
}
```