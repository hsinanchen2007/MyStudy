执行用时 :
8 ms
, 在所有 PHP 提交中击败了
93.95%
的用户
内存消耗 :
14.7 MB
, 在所有 PHP 提交中击败了
92.86%
的用户
```
function longestCommonPrefix($strs) {
        $prefix = '';
        $i = 0;
        if(count($strs)<1){
            return $prefix;
        }
        while(true){
            $current = $strs[0]{$i};
            if(!$current){
                return $prefix;
            }
            foreach($strs as $str){
                if($str{$i} != $current){
                    return $prefix;
                }
            }
            $prefix .= $current;
            $i++;
        }
        return $prefix;
    }
```
