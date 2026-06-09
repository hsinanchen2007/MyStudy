### 解题思路
思路见热度最高的那位老哥，下面是PHP代码的实现以及我自己的理解。

注意 `($a & $b) ==0 `，不要写 `$a & $b == 0`，运算符优先级的问题会出错。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function singleNumbers($nums) {
        //0和任何数异或都是数本身，所以ret是所有数异或的结果
        //相同的数异或为0，所以ret其实是那两个不同的数异或的结果
        $ret = 0;
        $a = 0;
        $b = 0;
        foreach ($nums as $num){
            $ret ^= $num;
        }

        //找到ret中第一个不为0的bit位，如果这位为1，那肯定能将不同的两个数分为不同的组
        $h=1;
        while(($ret & $h) == 0){
            $h <<= 1;
        }

        //依据上面不为1的那位，进行分组，相同的数字肯定被分到一起；
        //由于这一位是ret为1的那位，异或为1证明不同的数字这位一定不同(一个是0一个是1)，那么依据此进行分组
        foreach ($nums as $num){
            if(($h & $num) == 0){
                $a ^= $num;
            }else{
                $b ^= $num;
            }
        }
        return [$a,$b];
    }
}
```