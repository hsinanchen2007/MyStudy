```
class Solution {

    /**
     * @param Integer[] $nums
     * @return String
     */
    function largestNumber($nums) {
     for ($i=0;$i<count($nums)-1;$i++) {
        for ($j=0;$j<count($nums)-$i-1;$j++) {
            // 判断前后相邻二位数组成的数字大小，我之前没想到出现数字 10 这种情况，直接用冒泡排序处理的，
            //结果不通过，这里把前后相邻二位数组成一个新数字比较大小，用.链接成一个新数字，此时组成的是字符串，转换成
            //数字做比较，接下来和冒泡差不多了就
            if ((int)($nums[$j].$nums[$j+1]) < (int)($nums[$j+1].$nums[$j])) {
                $tmp = $nums[$j];
                $nums[$j] = $nums[$j+1];
                $nums[$j+1] = $tmp;
            } 
        }
    }
    // 这里把数组换成字符串
    $return = implode('',$nums);
    //这里判断是否返回‘0’，如果数组全是 0，此时返回的$retyrn == '0';'00' == '0';
    if ($return == '0') {
        $return = "0";
    }
    return $return;
    }
    
}
```
