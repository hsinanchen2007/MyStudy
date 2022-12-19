![微信截图_20190829200040.png](https://pic.leetcode-cn.com/0a3612f5871fa69ba6d25a98d6a4dbda402a9c6bd2b42458743648fd5851ea51-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190829200040.png)

```
function findSubstring($s, $words) {
    if(empty($words)) return [];
    $all_kv = [];
    foreach($words as $v){
        $match_kv[$v] = 0;
        if(empty($all_kv[$v])){
            $all_kv[$v] = 1;
        }else{
            $all_kv[$v] ++;
        }
    }
    $wordslength = strlen($words[0]);
    $wordscount = count($words);
    if(strlen($s) - $wordslength*$wordscount<0) return [];
    $res = [];
    for($i=0;$i<strlen($s) - $wordslength*$wordscount + 1;$i++){
        $tmp_match_kv = $match_kv;
        $num = 0;
        while($num<$wordscount){
            $slice_s = substr($s,$i+$num*$wordslength,$wordslength);
            if(array_key_exists($slice_s,$all_kv)){
                $tmp_match_kv[$slice_s]++;
                if($tmp_match_kv[$slice_s] > $all_kv[$slice_s]) break;
            }else{
                break;
            }
            $num++;
        }
        if($num == $wordscount){
            $res[] = $i;
        }
    }
    return $res;
}
```
