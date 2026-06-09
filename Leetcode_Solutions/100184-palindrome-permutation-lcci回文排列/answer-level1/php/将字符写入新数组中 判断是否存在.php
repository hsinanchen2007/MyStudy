将字符写入新数组中 判断是否存在 如果存在unset 如果不存在 随便存个数字 ，依次类推 若最后新数组长度小于等于1  则说明成立

class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function canPermutePalindrome($s) {
       $arr=str_split($s);
       $new=[];
       foreach($arr as $v){
           if(isset($new[$v])){
                unset($new[$v]);
           }else{
               $new[$v]=1;
           }
       }
       if(count($new)<=1)return true;
       return false;
    }
}