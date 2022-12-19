执行用时 :64 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :16 MB, 在所有 PHP 提交中击败了100.00%的用户
```
class Solution {

    /**
     * @param String[] $words
     * @return Integer
     */
    function minimumLengthEncoding($words) {
        $arrIndex = array();
        $intRet = 0;
        foreach($words as $word){
            if((isset($arrIndex[$word]) || isset($arrIndex['-'.$word]))){
                continue;
            }
            $intWLen = strlen($word);
            $flag = 0;
            for($i=0;$i<$intWLen;$i++){
                $strVal = $i==0 ? '-'.substr($word,$i) : substr($word,$i);
                if(isset($arrIndex['-'.$strVal])){
                    $flag = strlen($strVal) + 1;
                    unset($arrIndex['-'.$strVal]);
                    break;
                }
                if(!isset($arrIndex[$strVal])){
                    $arrIndex[$strVal] = 1;
                }
            }
            $intRet = $intRet + $intWLen + 1 - $flag;
        }
        return $intRet;
    }
}
```
