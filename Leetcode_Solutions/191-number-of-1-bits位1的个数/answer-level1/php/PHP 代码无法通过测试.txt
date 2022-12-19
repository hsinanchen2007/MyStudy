```
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function hammingWeight($n) {
        $count = 0;
        while ($n > 0) {
            $count += $n & 1;
            $n = $n >> 1;
        }
        
        return $count;
    }
}
```

代码在自己电脑上通过了测试，这里的测试都通不过，不知道什么原因。