给代码加了个注释。
思路：可能情况大概也就这三种：
1 2 3
1 9 9
9 9 9

```
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        $len = count($digits);
        //第一步、倒着遍历这个数组，因为是给最后一位加一开始
        for($i = $len-1; $i>=0; $i--){
            //第二步、给当前位置加1 
            $digits[$i]++;
            //第二步、该位置加1后和10取余 如果加一后是10， 则该值变为了0  如果不是10 ，取余后那还是它自己
            $digits[$i] = $digits[$i] % 10;

            //第三步、用0判断 判断上面那步是否是10 如果不是 则直接返回数组，说明没有进位，如果是0 那就说明有进位，则再次循环，给上一位加1，轮询判断。
            if($digits[$i] != 0){
                return $digits;
            }
        }

        //如果到这一步了，说明数组里的数都加完了，都需要进位了，比如999这种情况，那就给数组前面塞入个1 变为1000
        array_unshift($digits,1);

        return $digits;
    }
}
```
