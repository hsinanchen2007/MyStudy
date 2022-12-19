# 方法一: 哈希表,冒泡排序
- 时间复杂度O(n²+n)
- 空间复杂度: 哈希表最坏情况O(n),冒泡排序属于原地排序O(1),返回前K项O(k) 总复杂度O(n+k)
- 
- 注: 字符判断
- a < b //true
- b < a // false
- coding > leetcode // false
```
class Solution {

    /**
     * @param String[] $words
     * @param Integer $k
     * @return String[]
     */
    function topKFrequent($words, $k) {
        $count = count($words);
        $hash = $key = [];
        # 生成哈希表
        for ($i=0;$i<$count;$i++) {
            if (!isset($hash[$words[$i]])) {
                $key[] = $words[$i];
                $hash[$words[$i]] = 1;
            } else {
                $hash[$words[$i]] += 1;
            }
        }
        $countQ = count($key);
        $out = [];
        # 冒泡排序
        for ($i=0;$i<$countQ;$i++) {
            for($j=$countQ-1;$j>$i;$j--){
                # 排序hash table中值大的项
                if ($hash[$key[$j]] > $hash[$key[$j-1]]) {
                    $tmp = $key[$j - 1];
                    $key[$j - 1] = $key[$j];
                    $key[$j] = $tmp;
                # 如果hash table中值相等,判断单次,按字母排序
                } elseif (($hash[$key[$j]] == $hash[$key[$j-1]]) && $key[$j] < $key[$j - 1]) {
                    $tmp = $key[$j - 1];
                    $key[$j - 1] = $key[$j];
                    $key[$j] = $tmp;
                }
            }
        }
        # 返回排序后前K项
        for ($i=0;$i<$countQ;$i++) {
            if ($i==$k) {
                break;
            }
            $out[] = $key[$i];
        }
        return $out;
    }
}
```
