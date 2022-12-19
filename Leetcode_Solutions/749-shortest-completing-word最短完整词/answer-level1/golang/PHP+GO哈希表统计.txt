- 建立哈希表映射统计,排除空格大小写等干扰
- 判断映射单词中字母个数
- 判断映射字母个数相等情况,判断单词长短
- ASCII中`A`与`a`相差32
```GO []
func shortestCompletingWord(licensePlate string, words []string) string {
    var out string
    var shortWordLen,wordLen int
    for _,val := range words {
        
        /***重复制作hash表***/
        hash := make(map[string]int)
        for _,v := range licensePlate{
            if _,has := hash[string(v)]; !has && v >= 'a' && v<= 'z' {
                hash[string(v)] = 1
            } else if _,has := hash[string(v)]; has && v >= 'a' && v<= 'z' {
                hash[string(v)] ++
            } else if _,has := hash[string(v+32)]; !has && v >= 'A' && v<= 'Z' {
                hash[string(v+32)] = 1
            } else if _,has := hash[string(v+32)]; has && v >= 'A' && v<= 'Z' {
                hash[string(v+32)] ++
            }
        }
        
        /**开始确定最短完整单词**/
        wordFlag := 0
        for _,word := range val {
            if _,ok := hash[string(word)]; ok && hash[string(word)] > 0 {
                wordFlag++
                hash[string(word)]--
            }
        }
        // 如果命中字符多于当前标记
        if wordFlag > shortWordLen {
            out,shortWordLen,wordLen = val,wordFlag,len(val)
        }
        // 如果命中字符一样多,并且单词长度比当前长度短
        if wordFlag == shortWordLen && wordLen > len(val) {
            out,wordLen = val,len(val)
        }
    }
    
    return out
}
```
```PHP []
class Solution {

    /**
     * @param String $licensePlate
     * @param String[] $words
     * @return String
     */
    function shortestCompletingWord($licensePlate, $words) {
        $hash = [];
        /****制作哈希表****/ 
        for ($i=0;$i<strlen($licensePlate);$i++) {
            if ($licensePlate[$i] >= 'a' && $licensePlate[$i] <= 'z' && !isset($licensePlate[$i])) {
                $hash[$licensePlate[$i]] = 1;    
            } elseif($licensePlate[$i] >= 'a' && $licensePlate[$i] <= 'z' && isset($licensePlate[$i])){
                $hash[$licensePlate[$i]]++;   
            } elseif ($licensePlate[$i] >= 'A' && $licensePlate[$i] <= 'Z' && !isset($licensePlate[$i])) {
                $hash[chr(ord($licensePlate[$i])+32)] = 1;    
            } elseif($licensePlate[$i] >= 'A' && $licensePlate[$i] <= 'Z' && isset($licensePlate[$i])){
                $hash[chr(ord($licensePlate[$i])+32)]++;   
            } 
            
        }
        
        $out = '';
        $shortWordLen = 0;
        $wordLen = 0;
        for ($i=0;$i<count($words);$i++) {
            $hashCopy = $hash;
            $wordFlag = 0;
            for ($j=0;$j<strlen($words[$i]);$j++) {
                if (isset($hashCopy[$words[$i][$j]]) && $hashCopy[$words[$i][$j]] > 0) {
                    $wordFlag++;
                    $hashCopy[$words[$i][$j]] --;
                }
            }
            if ($wordFlag>$shortWordLen) {
                $out = $words[$i];
                $shortWordLen = $wordFlag;
                $wordLen = strlen($words[$i]);
            }
            if ($wordFlag==$shortWordLen && $wordLen > strlen($words[$i])) {
                $out = $words[$i];
                $wordLen = strlen($words[$i]);
            }
            
        }
        return $out;
    }
}
```
