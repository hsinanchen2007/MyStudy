### 解题思路
看了很久才理解了题目，就是如果尾数为9要向前一位+1

### 代码

```php
class Solution {

   function plusOne($digits) {
    $len = count($digits);
    $flag = 1;
    for ($i = $len-1; $i >= 0; $i--){
        // 不等于9 ; +1 可以直接退出
        if($digits[$i] != 9){
            $digits[$i] += $flag;
            $flag = 0;
            break;
        } else {
            $digits[$i] = 0;
            if($i == 0){
                array_unshift($digits, 1);
            }
            $flag = 1;
        }



    }

    return $digits;
}
}
```