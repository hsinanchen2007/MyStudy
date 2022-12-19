class Solution {

    /**
     * @param String $s
     * @param String[] $words
     * @return Integer[]
     */
    function findSubstring($s, $words) {
        //先排序，用于后面找到的字串进行数组键值严格比较
        sort($words);
        $one_word_len = strlen($words[0]);
        $words_len = $one_word_len * count($words);

        $s_len = strlen($s);

        $rs = [];
        $end_pos = $s_len - $words_len;
        //先对$words去重，因为同样的单词查找是一样的
        foreach(array_unique($words) as $v) {
            //查找有效的开始位置
            $start_pos = strpos($s, $v);
            if($start_pos !== false) {
                //查找所有匹配到的单词，$i为遍历$s的索引
                for($i = $start_pos; $i <= $end_pos; $i++) {
                    if(strpos(substr($s, $i), $v) !== false) {
                        $temp = substr($s, $i, $words_len);
                        $temp = str_split($temp, $one_word_len);
                        sort($temp);
                        if(!in_array($i, $rs) && !array_diff_assoc($words, $temp)) {
                            $rs[] = $i;
                        }
                    }
                
                }
            }

        }

        return $rs;
        
    }
}