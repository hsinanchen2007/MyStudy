![image.png](https://pic.leetcode-cn.com/135848515e0505d93ff9c0d9da3ae281cfacc2462d6cf4eb61bcf6cb830e5287-image.png)
注:
1. 判断是否为空
2. 判断末尾不为9的情况
3. 判断[9],[9,9]首位为9的情况
4. 遇到不为9时将值+1,然后退出并返回
```
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        if (empty($digits)) {
            return [];
        }
        $count = count($digits);
        if ($digits[$count-1]!=9) {
            $digits[$count-1] += 1;
            return $digits;
        }
        if ($digits[0]==9) {
            array_unshift($digits, 0);
            $count = count($digits);
        }

        $r = $count - 1;
        while ($r>=0) {
            if ($digits[$r] == 9) {
                $digits[$r] = 0;
                $r--;
                continue;
            }
            if ($digits[$r] != 9) {
                $digits[$r] += 1;
                break;
            }
            $r--;
        }
        return $digits;
    }
}
```
