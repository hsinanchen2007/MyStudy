### 解题思路
把每个字符串排序之后比较，如果一样就是异位词

### 代码

```php
class Solution {

    /**
     * @param String[] $strs
     * @return String[][]
     */
    function groupAnagrams($strs) {
        $map = array();
        for( $i = 0 ; $i < count( $strs ) ; $i ++ ) {
            $arr = str_split( $strs[$i] );
            sort( $arr  );
            $x = implode('', $arr);
            $map[ $x ][$i] = $strs[$i];
            
        }
        return $map;
    }
}
```