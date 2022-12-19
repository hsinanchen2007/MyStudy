class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
    
        $index =0;
        if($x<0){
            $index=1;
        }
        try{
            $need_recv = substr($x,$index);
            $new_str = strrev($need_recv);
            $num = $index? 0 -intval($new_str):intval($new_str);
            if($num>pow(2,31)-1 || $num<pow(-2,31)){
                throw new Exception('产生溢出了');
            }
            return $num;
        }catch(Exception $e)
        {
            return 0;
        }

    }
}

![image.png](https://pic.leetcode-cn.com/e632da849e1e29c8fca9155a877dbb0f415a96b72629fd01191c0b2b5b3bc59f-image.png)

