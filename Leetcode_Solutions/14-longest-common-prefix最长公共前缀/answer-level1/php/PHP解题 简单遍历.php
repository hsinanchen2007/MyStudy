php遍历解题 仅供参考
```
class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
   function longestCommonPrefix($strs) {
        if(empty($strs)){
            return '';
        }
        if(count($strs) == 1){
            return $strs[0];
        }
        foreach($strs as $v)
        {
            $len = strlen($v);
            $b[] = $len;
        }
        $min = min($b);
        $first = $strs[0];
        array_shift($strs);
        foreach($strs as $v)
        {
            $str = $this->common($first,$v,$min);
            if($str == '')
            {
                return '';
            }
            $c[] = $str;
        }
        sort($c);
        return $c[0];
    }

    function common($str1,$str2,$min){
        $str = '';
        for($i=0;$i<$min;$i++)
        {
            if($str1[$i] == $str2[$i])
            {
                $str .= $str1[$i];
            }
            else{
                break;
            }
        }
        return $str;
    }
}
```

