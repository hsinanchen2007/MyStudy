### 解题思路
具体思路如下，从最左往右推进，如遇到未遇到的字母则添加至哈希表，并把当前index写入并加一，如遇到已有字母则把已有字母index替换为当前值

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */

    function lengthOfLongestSubstring($s) {
        $size = strlen($s);
        if($size<2) return $size;//return the size of array if size less than 2
        $map = [];//initiate the hash map
        $max = 0;//initiate the max substring length
        $start = 0;//initiate the starting point

        for($i=0;$i<$size;$i++){
            //if current character existing in hash map, compare the starting point and current
            //character position and return the bigger number
            if(isset($map[$s[$i]])) $start = max($map[$s[$i]], $start);
            // echo substr($s,$start,$i-$start+1) . "\n";

            //set the max substring length to be bigger number between
            //the current substring length and current max val
            $max = max($max, $i-$start+1);

            //shift the current ending point to the right by 1
            $map[$s[$i]] = $i + 1;
        }

        return $max;
    }
}
```