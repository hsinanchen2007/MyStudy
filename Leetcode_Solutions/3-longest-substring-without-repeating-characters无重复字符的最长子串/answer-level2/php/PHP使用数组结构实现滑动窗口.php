写法比较笨,但是能达到滑动窗口效果,仅供参考
```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $count = strlen($s);
        $tem = []; // 临时字符串数组
        $value = 0;// 无重复字符串计数变量
        # 空字符串情况
        if ($count < 1) {
            return $value;
         }
        #循环字符串
        for ($i=0;$i<$count;$i++) {
            # 字符串不存在数组则加入
            if (!in_array($s[$i], $tem)) {
                $tem[] = $s[$i];
            } else {
                # 遇到在数组中 计算当前数组总数是否大于计数器中的值
                if (count($tem) > $value) {
                    $value = count($tem);
                }
                # 找到该重复的下标
                $index = array_search($s[$i], $tem);
                # 将重复字符之前的字符串干掉
                $tem = array_slice($tem, $index+1, $count);
                # 干掉后继续添加新的字符进来
                $tem[] = $s[$i];
            }
            # 当走到最后一个字符,判断当前数组长度,看是否更新计数
            if ($i == $count - 1 && $tem && count($tem) > $value) {
                $value = count($tem);
            }
        }
        return $value;
    }
}
```