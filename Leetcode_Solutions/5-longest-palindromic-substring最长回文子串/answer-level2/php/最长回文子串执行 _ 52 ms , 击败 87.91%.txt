中心扩展算法 加上 中心扩展 
因为是要找最长回文子串，所以字符串首尾都有很大可能产生垃圾数据
可以直接从字符串中间位置往首尾分别扩展
当剩余的字符不足以产生最长回文，则舍弃

```
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function longestPalindrome($s) {
        $len = strlen($s);
        $max = '';
        $center = intval($len/2)-1;
        for($i=$center;$i<$len;$i++){
            if(($len-$i-1)*2<=strlen($max)){
                break;
            }
            if($s[$i]==$s[$i+1]){
                $tmp1 = $this->getmax($i,$i+1,$s,$len);
            }
            if($s[$i] == $s[$i+2]){
                $tmp2 = $this->getmax($i,$i+2,$s,$len,$s[$i+1]);
            }
            $tmp = strlen($tmp1)>strlen($tmp2)?$tmp1:$tmp2;
            $max = strlen($tmp)>strlen($max)?$tmp:$max;
        }
        for($i=$center+1;$i>=0;$i--){
            if(($i*2)<=strlen($max)){
                break;
            }
            if($s[$i]==$s[$i-1]){
                $tmp1 = $this->getmax($i-1,$i,$s,$len);
            }
            if($s[$i] == $s[$i-2]){
                $tmp2 = $this->getmax($i-2,$i,$s,$len,$s[$i-1]);
            }
            $tmp = strlen($tmp1)>strlen($tmp2)?$tmp1:$tmp2;
            $max = strlen($tmp)>strlen($max)?$tmp:$max;
        }
        return $max==''?$s[0]:$max;

    }

    function getmax($start,$end,$s,$len,$center=''){
        $step = 1;
        $max = $center;
        
        while($start>=0 && $end < $len){
            if($s[$start]==$s[$end]){
                $max = $s[$start].$max.$s[$end];
            }else{
                break;
            }
            $start--;
            $end++;
        }
        return $max;
    }

}
```
