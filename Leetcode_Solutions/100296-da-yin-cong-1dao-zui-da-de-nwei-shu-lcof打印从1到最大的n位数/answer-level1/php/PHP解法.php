### 解题思路
常规解法
### 代码

```php
class Solution {

   /**
     * @param Integer $n
     * @return Integer[]
     */
    function printNumbers($n) {
        if($n==0) return [];
        $nums=[];

        for($i=1;$i<pow(10,$n);$i++){
            array_push($nums,$i);
        }
        return $nums;
    }
}
```