```
    class Solution {

        /**
        * @param String $s
        * @return Integer
        */
        function lengthOfLongestSubstring($s) {
            $count = strlen($s);
            $max = $len = 0;
            $arr = [];
            $i = $j = 0;
            while ($j < $count) {
                if (isset($arr[$s[$j]]) && $arr[$s[$j]] >= $i) {
                    $i = $arr[$s[$j]];
                    $len = $j - $i;
                } else {
                    $len++;
                }
                if ($max < $len) $max = $len;
                $arr[$s[$j]] = $j;
                $j++;
            }
            return $max;
        }
    }
```
> 滑动窗口

- 假如有字符串dababc
- 滑动窗口开始时i=j=0,得到d是所求的
- i=0,j=1   da是所求
- i=0,j=2   dab是所求
- i=0,j=3   daba不是所求，a重复了，此时第一个a的下标为index=1,那么滑动窗口的i此时应该修改成index+1
- i=2,j=3   ab才是所求
- ....
- 所以归根到底就是怎么更有效地得出i、j、index
- j很简单，拿到字符串长度，然后循环时j++就是所求
- i初始值为0，后续都是根据index获取
- 可以定义一个关联数组arr,键名为字符，键值为字符所在位置(index，index需要大于i)，判断字符重复时直接用isset/array_key_exists即可(或者也可以用字符串形式，查找字符串中字符位置)
- 力扣执行代码有误差，同样的代码有时候20ms，4ms，32ms都有
