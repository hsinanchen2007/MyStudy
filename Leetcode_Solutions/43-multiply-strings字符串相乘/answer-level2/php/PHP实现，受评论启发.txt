
启发来自：[LeetCode : 43. 字符串相乘（Multiply Strings）解答
](https://blog.csdn.net/afei__/article/details/83891547)

class Solution {

    /**
     * @param String $num1
     * @param String $num2
     * @return String
     */
    function multiply($num1, $num2) {
        if ($num1 == '0' || $num2 == '0') {
            return '0';
        }
        $arr = [];
        $len1 = strlen($num1);
        $len2 = strlen($num2);
        $arr[0] = 0;
        for ($i=0; $i<$len1; $i++) {
            for ($j = 0; $j < $len2; $j++) {
                isset($arr[$i+$j+1])? '' : $arr[$i+$j+1] = 0;
                $arr[$i+$j+1] +=  (int) $num1[$i] * (int) $num2[$j];
            }
        }

        
        $is = 0;
        $count = count($arr);
        for ($i=$count-1; $i>=0; $i--) {
            $arr[$i] += $is;
            $is = floor($arr[$i]/10);
            $arr[$i] = $arr[$i]%10;
        }

        return ltrim(implode('', $arr), '0');
    }
}