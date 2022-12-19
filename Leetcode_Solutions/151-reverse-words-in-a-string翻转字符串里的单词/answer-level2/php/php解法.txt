### 解题思路
利用PHP自带的函数 轻松解决了~ 

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        $arr = explode(" ",$s);
        foreach($arr as $key=>$vlaue){
            if($vlaue == ''){
                unset($arr[$key]);
                continue;
            }
            $arr[$key] = trim($vlaue);
        }
        $newArr = array_reverse($arr);
        $newStr = implode(" ",$newArr);

        return $newStr;
    }

}
```