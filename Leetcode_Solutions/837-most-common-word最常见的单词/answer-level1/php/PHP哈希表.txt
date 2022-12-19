- 建立哈希表并且计数
- 遍历哈希表 过滤禁用列表单词
- 选出第一个没有在禁用列表中的单词
```
class Solution {

    /**
     * @param String $paragraph
     * @param String[] $banned
     * @return String
     */
    function mostCommonWord($paragraph, $banned) {
        $count = strlen($paragraph);
        $word = "";
        $hash = $hash2 = [];
        // 清洗数据,建立段落单词哈希表
        for ($i=0;$i<$count;$i++) {
            $letter = $this->isLetter($paragraph[$i]);
            if ($letter) {
                $word .= $letter;
            } elseif($word != "") {
                $hash = $this->setHash($hash,$word);
                $word = "";
            }            
            // 注意边界判断
            if ($i==$count-1 && $word) {
                $hash = $this->setHash($hash,$word);
            }
        }
        // 排序
        arsort($hash);
        // 禁用词建立哈希表
        foreach ($banned as $value) {
            $hash2[$value] = true;
        }
        $out = "";
        // 筛选出单词
        foreach ($hash as $key=>$value) {
            if (!isset($hash2[$key])) {
                $out = $key;
                break;
            }
        }
        return $out;
    }
    
    # 哈希表处理
    function setHash($hash, $word){
        if (!isset($hash[$word])) {
            $hash[$word] = 1;
        } else {
            $hash[$word] ++;
        }
        return $hash;
    }
    # 转换大小写
    function isLetter ($str) {
        if ($str >= 'a' && $str <= 'z') {
            return $str;
        } elseif ($str >= 'A' && $str <= 'Z') {
            return chr(ord($str) + 32);
        }
        return false;
    }
}
```
