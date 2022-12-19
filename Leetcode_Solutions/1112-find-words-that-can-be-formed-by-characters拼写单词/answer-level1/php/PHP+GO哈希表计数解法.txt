- 通过字母建立哈希表并且计数
- 遍历每个单词匹配字母匹配
```PHP []
class Solution {

    /**
     * @param String[] $words
     * @param String $chars
     * @return Integer
     */
    function countCharacters($words, $chars) {
        $hash = [];
        $count = strlen($chars);
        $arrCount = count($words);
        for ($i=0;$i<$count;$i++) {
            if (!isset($hash[$chars[$i]])) {
                $hash[$chars[$i]] = 1;
            } else {
                $hash[$chars[$i]] += 1;
            }
        }
        $out = 0;
        for ($i=0;$i<$arrCount;$i++) {
            $wordLen = strlen($words[$i]);
            $hashCopy = $hash;
            $ok = true;
            for ($j=0;$j<$wordLen;$j++) {
                if (!isset($hashCopy[$words[$i][$j]])) {
                    $ok = false;
                    break;
                }
                if (isset($hashCopy[$words[$i][$j]]) && $hashCopy[$words[$i][$j]] > 1 ) {
                    $hashCopy[$words[$i][$j]] -= 1;
                } elseif ($hashCopy[$words[$i][$j]] == 1) {
                    unset($hashCopy[$words[$i][$j]]);
                }
                
            }
            if ($ok) {
                $out += $wordLen;
            }
        }
        return $out;
    }
}
```
```GO []
func countCharacters(words []string, chars string) int {
    out := 0
    for _,v := range words {
        times := 0
        hash := make(map[string]int)
        for _,c := range chars{
            if _,ok := hash[string(c)]; !ok {
                hash[string(c)] = 1
            } else {
                hash[string(c)]++
            }
        }
        
        for _,val := range v {
            if _,has := hash[string(val)]; has && hash[string(val)] > 0{
                times++
                hash[string(val)] --
            }
        }
        if times == len(v) {
            out += len(v)
        }
    }
    return out
}
```
