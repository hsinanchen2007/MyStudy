1. 判断两个长度是否相等
2. 建立双哈希表映射
3. 将key转换成索引方便映射
4. 遍历哈希表判断映射位置
```
class Solution {

    /**
     * @param String $pattern
     * @param String $str
     * @return Boolean
     */
    function wordPattern($pattern, $str) {
        $arr = explode(' ', $str);
        $count = strlen($pattern);
        $count2 = count($arr);
        if ($count != $count2) {
            return false;
        }
        $hash = $hash2 = [];
        for ($i=0;$i<$count;$i++) {
            $hash[$pattern[$i]][] = $i;
        }
        foreach ($arr as $key=>$value) {
            $hash2[$value][] = $key;
        }
        
        sort($hash);
        sort($hash2);
        foreach ($hash as $key=>$value) {
            foreach ($value as $k=>$v) {
                if ($v != $hash2[$key][$k]) {
                    return false;
                }
            }
        }
        return true;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * $obj = MyHashMap();
 * $obj->put($key, $value);
 * $ret_2 = $obj->get($key);
 * $obj->remove($key);
 */
```
