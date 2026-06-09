### 解题思路
修修补补

### 代码

```php
class Solution {

    /**
     * @param String $pattern
     * @param String $str
     * @return Boolean
     */
    function wordPattern($pattern, $str) {
    $strs = explode(" ", $str);
    if(strlen($pattern)!=count($strs))
        return false;
    $arr = array();  //["dog"=>"a"]

    for($i=0; $i+1<strlen($pattern); $i++)
    {
        if($strs[$i] == $strs[$i+1] && $pattern[$i]!=$pattern[$i+1])
        {
            return false;
        }
        if(!isset($arr[$pattern[$i]]))
            $arr[$pattern[$i]] = $strs[$i] ;
        if(!isset($arr[$pattern[$i+1]]))
            $arr[$pattern[$i+1]] = $strs[$i+1] ;
        if($strs[$i]!=$arr[$pattern[$i]] || $strs[$i+1]!=$arr[$pattern[$i+1]])
            return false;
        
    }
    return true;
    }
}
```