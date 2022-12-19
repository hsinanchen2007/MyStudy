### 解题思路
n × n 的二维矩阵顺时针旋转 90°，既从矩阵最后一行开始依次加入原矩阵每行最后一位
[1,2,3]
[4,5,6]
[7,8,9]
旋转矩阵使其变为2n × n 的矩阵
[1,2,3|7,4,1]
[4,5,6|8,5,2]
[7,8,9|9,6,3]
再删除新矩阵每行前n项
### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return NULL
     */
    function rotate(&$matrix) {
        $tem = count($matrix)-1;
        for ($i = 0; $i < count($matrix); $i++) {
            for ($j= 0; $j< count($matrix); $j++) {
                array_push($matrix[$i],$matrix[$tem-$j][$i]);
            }
        }
        for ($k = 0; $k < $tem+1; $k++) {
            array_splice($matrix[$k], 0, $tem+1);
        }
        return $matrix;
    }
}
```