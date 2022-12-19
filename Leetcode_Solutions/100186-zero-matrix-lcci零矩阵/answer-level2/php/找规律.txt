### 解题思路
把开始的点作为 xy轴的起点。遍历数组，然后就在xy轴标记。

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return NULL
     */
    function setZeroes(&$arr) {
        $x = $y = false;
      $i = $j = 0;
      $ly = count($arr);
      $lx = count($arr[0]);
      while($i < $ly && $j < $lx ){
        if($arr[$i][$j] == 0){
          if($i == 0){
            $x = true;
          }
          if($j == 0){
            $y = true;
          }
          $arr[0][$j] = 0;
          $arr[$i][0] = 0;
        }
        $j++;
        if($j >= $lx ){
          $i++;
          $j = 0;
        }
      }

      $i = 1;
      while ($i < $ly) {
          if($arr[$i][0] == 0){
            $n = 0;
            while ($n < $lx) {
              $arr[$i][$n] = 0;
              $n++;
            }
          }
          $i++;
      }

      $j = 1;
      while ($j < $lx) {
          if($arr[0][$j] == 0){
            $n = 0;
            while ($n < $ly) {
              $arr[$n][$j] = 0;
              $n++;
            }
          }
          $j++;
      }

      if($x){
        $n = 0;
        while ($n < $lx) {
          $arr[0][$n] = 0;
          $n++;
        }
      }

      if($y){
        $n = 0;
        while ($n < $ly) {
          $arr[$n][0] = 0;
          $n++;
        }
      }
    }
}
```