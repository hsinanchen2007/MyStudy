
第一次500ms 
`function findSubstring($s, $words)
    {
        if (empty( $words )) {
            return [];
        }
        sort( $words );
        $strLen  = strlen( $words[0] );
        $wordLen = count( $words ) * $strLen;
        $len     = strlen( $s );
        $arr     = [];
        for ($i = 0; $i < $len - $wordLen + 1; $i++) {
            $temp = str_split( substr( $s, $i, $wordLen ), $strLen );
            sort( $temp );
            if (!array_diff_assoc( $words, $temp )) {
                $arr[] = $i;
            }
        }
        return $arr;
    }

    function one($s, $words)
    {
        if (empty( $words )) return [];
        $word_Kv = [];
        $temp    = [];
        foreach ($words as $word) {
            $temp[$word] = 0;
            if (empty($word_Kv[$word])) {
                $word_Kv[$word] = 1;
            } else {
                ++$word_Kv[$word];
            }
        }
        $wordLen  = strlen( $words[0] );
        $count    = count( $words );
        $wordsLen = $count * $wordLen;
        $strLen   = strlen( $s );
        $arr      = [];
        for ($i = 0; $i < $strLen - $wordsLen + 1; $i++) {
            $num   = 0;
            $match = $temp;
            while ($num < $count) {
                $str = substr( $s, $i + $num * $wordLen, $wordLen );
                if (array_key_exists( $str, $word_Kv )) {
                    ++$match[$str];
                    if ($match[$str] > $word_Kv[$str]) {
                        break;
                    }
                } else {
                    break;
                }
                $num++;
            }
            if ($num == $count) {
                $arr[] = $i;
            }
        }
        return $arr;
    }

`