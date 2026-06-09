`class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        
        $len = 0; // 最长的长度
        
        $temp = ''; // 临时队列
        $strlen = strlen($s);
        $temp_len = 0; // 临时队列的长度

        for ($i = 0; $i< $strlen; $i++) { // 遍历字符串取出单个字符
            
            $key = strpos($temp, $s[$i]); // 获取临时队列中已存在的该字符的下标
            $temp .= $s[$i]; // 拼接进队列
            if ($key === false) { // 临时队列中不存在该字符
                $temp_len++; // 临时长度变长
                if ($temp_len > $len) { // 临时长度大于总长度
                    $len = $temp_len;
                }
            } else { 
                // 临时队列中存在该字符，便从该字符的后一位截取出新的队列，并将临时队列长度赋值为当前的队列长度。
                // 这里需要理解，当出现重复字符的时候，截止到第二个重复字符之前的队列长度已经是当时最长的了，
                // 除非把第一个重复字符剔除掉，然后从第一个重复字符的下个字符 到第二个重复字符为基础 继续向下拼接统计。（队列中只能出现一次该字符）
                $temp = substr($temp, $key+1);
                $temp_len = strlen($temp);
            }
            
        } 
        
        return $len;
    }
}`