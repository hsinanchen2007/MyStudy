class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
  function reverse($x) {
    if($x<0){
        $a = intval("-".strrev(rtrim(abs($x),0)));
          if($a<pow(-2,31)) {
              return 0;
          } else {
        return $a;
        }
    } else {
        $a =intval(strrev(rtrim($x,0)));
         if($a>pow(2,31)-1) {
              return 0;
          } else {
        return $a;
        }
    }
}
}