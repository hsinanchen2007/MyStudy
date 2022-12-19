将每个字符串按照字母顺序排序，这样的话就可以把这些字符串都映射到map中对应起来
```
class Solution {

    /**
     * @param String[] $strs
     * @return String[][]
     */
    function groupAnagrams($strs) {
        $map = [];
        foreach($strs as $str){
            $tmp_str = $this->formatAtoZ($str);
            $map[$tmp_str][] = $str;
        }
        return $map;
    }
    
    function formatAtoZ($str){
        $arr = str_split($str);
        sort($arr);
        return implode("",$arr);
    }
}
```
