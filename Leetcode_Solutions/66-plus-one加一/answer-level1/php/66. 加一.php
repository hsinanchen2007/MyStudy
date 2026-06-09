### 解题思路
1. 遍历数组（从右到左）
2. 当前元素为9时，9->0 继续；
3. 当前元素非9时，+1 结束遍历；
4. '000' 情况首位0->1，尾部补充0
5. 时间复杂度：O(n)

### 代码

```php
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        $length = count($digits);
        for($i=$length-1; $i>=0; $i--){
            if($digits[$i] == 9){
                $digits[$i] = 0;
                continue;
            }
            $digits[$i] += 1;
            break;
        }
       
        if($digits[0] == 0){
            $digits[0] = 1;
            $digits[$len] = 0;
        }
        return $digits;
    }
}
```