利用PHP中的array_unique 函数

class Solution {

    /**
     * @param String $astr
     * @return Boolean
     */
    function isUnique($astr) {
            $length = strlen($astr);
            if($length <= 1){
                return true;
            }
            for($i=0;$i<$length;$i++){
                $check = substr($astr,$i,1);
                $arr[] = $check;
            }

            if(count($arr) == count(array_unique($arr))){
                return true;
            }else{
                return false;
            }
    }
}
