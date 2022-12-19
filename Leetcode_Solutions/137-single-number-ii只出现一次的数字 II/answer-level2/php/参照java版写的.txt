### 解题思路
以上过程本质上是通过构建 33 个变量的状态转换表来表示对应位的出现次数：使所有数字“相加”后出现 3N+13N+1 次的位 ones = 1ones=1，出现 3N，3N+23N，3N+2 次的位为 ones = 0ones=0。由于 threethree 其实是 ones & twos 的结果，因此我们可以舍弃 threesthrees，仅使用 onesones 和 twostwos 来记录出现次数。
某位出现	1次	2次	3次	4次	5次	6次	...
ones	1	0	0	1	0	0	...
twos	0	1	0	0	1	0	...
threes	0	0	1	0	0	1	...
代码分析：
ones = ones ^ num & ~twos：
当 num = 1num=1 时，只当 ones = twos = 0ones=twos=0 时将 onesones 置 11，代表出现 3N+13N+1 次；其余置 00，根据 twostwos 值分别代表出现 3N3N 次和 3N+23N+2 次；
当 num = 0num=0 时，onesones 不变；
twos = twos ^ num & ~ones：
当 num = 1num=1 时，只当 ones = twos = 0ones=twos=0 时将 twostwos 置 11，代表出现 3N+23N+2 次；其余置 00，根据 onesones 值分别代表出现 3N3N 次和 3N+13N+1 次。
当 num = 0num=0 时，twostwos 不变。

作者链接：https://leetcode-cn.com/problems/single-number-ii/solution/

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        $arr=[];
        foreach($nums as $value){
            if(!isset($arr[$value])){
                $arr[$value] = 1;
            }else{
                $arr[$value]++;
            }
        }
        foreach($arr as $key => $value){
            if($value == 1){
                return $key;
            }
        }
        return 0;
        
    }
}
```