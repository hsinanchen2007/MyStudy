class Solution {

    /**
     * @param String[][] $board
     * @param String $word
     * @return Boolean
     */
    function exist($board, $word) {
        foreach($board as  $rowIndex => $row){
            foreach($row as $columnIndex => $column){
                if($board[$rowIndex][$columnIndex] != $word[0]){
                    continue;
                }else{
                    $path = [];
                    $token = strval($rowIndex).'_'.strval($columnIndex);
                    $path[$token] = $column;
                    $result = $this->includeChar($word,1,$board,$rowIndex,$columnIndex,$path);
                    if($result == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    function includeChar($str,$strIndex,$board,$i,$j,&$path){
        if($strIndex == strlen($str)){
            return true;
        }
        //左 有这个元素 & 这个元素没有在路径中出现过 & 这个元素是当前元素
        $token = strval($i) . '_' . strval($j-1);
        if(isset($board[$i][$j-1]) && !isset($path[$token]) && $str[$strIndex] == $board[$i][$j-1]){
            $path[$token] = $board[$i][$j-1];
            $result = $this->includeChar($str,$strIndex+1,$board,$i,$j-1,$path);
            if($result == true){
                return true;
            }else{
                unset($path[$token]);
            }
        }
        //右
        $token = strval($i) . '_' . strval($j+1);
        if(isset($board[$i][$j+1]) && !isset($path[$token]) && $str[$strIndex] == $board[$i][$j+1]){
            $path[$token] = $board[$i][$j+1];
            $result = $this->includeChar($str,$strIndex+1,$board,$i,$j+1,$path);
            if($result == true){
                return true;
            }else{
                unset($path[$token]);
            }
        }
        //上
        $token = strval($i-1) . '_' . strval($j);
        if(isset($board[$i-1][$j]) && !isset($path[$token]) && $str[$strIndex] == $board[$i-1][$j]){
            $path[$token] = $board[$i-1][$j];
            $result = $this->includeChar($str,$strIndex+1,$board,$i-1,$j,$path);
            if($result == true){
                return true;
            }else{
                unset($path[$token]);
            }
        }
        //下
        $token = strval($i+1) . '_' . strval($j);
        if(isset($board[$i+1][$j]) && !isset($path[$token]) && $str[$strIndex] == $board[$i+1][$j]){
            $path[$token] = $board[$i+1][$j];
            $result = $this->includeChar($str,$strIndex+1,$board,$i+1,$j,$path);
            if($result == true){
                return true;
            }else{
                unset($path[$token]);
            }
        }
        return false;
    }
}