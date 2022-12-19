![1071.png](https://pic.leetcode-cn.com/050567cc1fd82df67836eda39d410af61706a05de0af600ea1b2bb3413cbd204-1071.png)

```
class Solution {

    function gcdOfStrings($str1, $str2) {

        $strlen1 = strlen($str1);
        $strlen2 = strlen($str2);

        for($len = $strlen2;$len > 0;$len--){
            if($strlen2 % $len != 0 || $strlen1 % $len != 0){
                continue;
            }
            for($start = 0; $strlen2 - $len >= $start;$start++){
                $str = substr($str2,$start,$len);
                if(substr_count($str1,$str) == ($strlen1/$len) && substr_count($str2,$str) == ($strlen2/$len)){
                    return $str;
                }

            }
        }
        return '';
    }
}
```
