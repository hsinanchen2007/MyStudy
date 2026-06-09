__滑动窗口法：__

注1. 所有不重复的字符最多有95个；
```
class Solution 
{
    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) 
    {
        $len = strlen($s);
        if ($len <= 1) {
            return $len;
        }
        $offset = $len;
        if ($offset > 95) {
            $offset = 95;
        }
        do {
            $num = $len - $offset + 1;
            for ($i = 0; $i < $num; $i ++) {
                $sub_s = substr($s, $i, $offset);
                $count = strlen($sub_s);
                if ($count === 1) {
                    return $count;
                }
                if ($this->isTrue($sub_s, $count)) {
                    return $count;
                }
            }
            $offset --;
        } while (true);
    }
    
    function isTrue($sub_s, $sub_s_count)
    {
        for ($j = 0; $j < $sub_s_count; $j ++) {
            $char = $sub_s{$j};
            if (strrpos($sub_s, $char) != $j) {
                return false;
            } 
        }
        return true;
    }
}
```

__仿java的php版本，膜拜大神，值得思考：__
```
class Solution 
{
    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) 
    {
        $i      = 0;
        $flag   = 0;
        $length = 0;
        $result = 0;
        
        $s_length = strlen($s);
        
        while ($i < $s_length) {
            
            $pos = strpos($s, $s{$i}, $flag);
            if ($pos < $i) {
                if ($length > $result) {
		    $result = $length;
		}
		if ($result >= $s_length - $pos - 1) {
		    return $result;
		}
		$length = $i - $pos - 1;
		$flag = $pos + 1;
            }
            
            $i ++;
            $length ++;
        }
        return $length;
    }
}
```