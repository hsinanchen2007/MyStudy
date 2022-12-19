### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
   function plusOne($digits) {
    $length = count($digits);
    for($i=$length-1; $i>=0; $i--){//从最后一位数往前面遍历
        if($digits[$i] == 9){//如果是9就变0,然后跳出
            $digits[$i] = 0;
            continue;
        }else{
            $digits[$i] += 1;//不是9就加1
            break;
        }
    }
     if($digits[0] == 0){//第一位为0说明都是9，把第一位变成1，再加一位0
        $digits[0] = 1;
        $digits[$length] = 0;
    }
    return $digits;
}
}
```