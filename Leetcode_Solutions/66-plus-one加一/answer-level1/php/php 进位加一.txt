class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        $len = count($digits);
        $digits[$len-1]+=1;
            for($i=$len-1;$i>0;$i--){
                $this->jinwei($digits[$i-1],$digits[$i]);
            }
            if($digits[0]==10){
                $digits[0]=1;
                $digits[$len]=0;
            }
            
        return $digits;
    }
    //进位处理
    public function jinwei(&$h,&$l){
        if($l==10){
            $l=0;
            $h=$h+1;
        }
    }
}