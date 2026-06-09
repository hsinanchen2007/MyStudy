### 解题思路
基本的数学解法 + 巧思解法

### 代码

```php
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        $count = count($digits);
        
        if($count==1 && $digits[0] == 0) return [1];//数组只有一位且为0
        
        $carry = 1;//因为要加一，所以初始进位值为一
        $res = [];//最终结果
        for($i=$count-1;$i>=0;$i--){//从最后一位（个位）开始
            $cur_sum = $digits[$i] + $carry;//当前位数与进位值的和
            if($cur_sum-10==0) {//出现进位，则当前位数重置为0，进位值为1
                $res[] = 0;
                $carry = 1;
            }
            else{//无需进位，则当前位数为和，进位值为0
                $res[] = $cur_sum;
                $carry = 0;
            } 
        }
        
        if($carry == 1) $res[] = 1;//如循环后还有进位值，则推入结果
        
        krsort($res);//按照反向index排列
        // print_r($res);
        return $res;
    }
}
```

高级解法
```php
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        $count = count($digits);
        if($count==1 && $digits[0] == 0) return [1];//数组只有一位且为0

        for($i=$count-1;$i>=0;$i--){
            //如果遇到数字9，说明9一定在原数组第一位，否则的话在下边else就直接返回了
            //此位数值为0
            if($digits[$i] == 9){
                $digits[$i] = 0;
            }
            else{
                $digits[$i] += 1;//当前数字加一小于10，无需进位，加一后直接返回数组
                return $digits;
            }
        }

        //循环结束后如果还能运行到这里，说明有进位，且其他位数皆为0，所以在头部加1，末尾加零
        //例如：[9] --> [0] --> [1,0]
        //[9,9] --> [0,0] --> [1, 0, 0]
        $digits[0] = 1;
        $digits[$count] = 0;

        return $digits;
    }
}
```