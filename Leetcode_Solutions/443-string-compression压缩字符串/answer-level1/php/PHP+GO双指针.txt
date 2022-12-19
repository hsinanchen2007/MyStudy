- 左右指针
- 注意最后边界

```PHP []
class Solution {

    /**
     * @param String[] $chars
     * @return Integer
     */
    function compress(&$chars) {
        /***
         * 新数组做操作后赋值给原数组
         */
        if (empty($chars)) return -1; 
        $count = count($chars);
        $arr = [];
        $times = 1;
        for ($i=0;$i<$count;$i++) {
            $next = $i+1;
            if ($chars[$i] != $chars[$next]) {
                $arr[] = $chars[$i];
                if ($times!=1) {
                    $str = (string)$times;
                    for ($j=0;$j<strlen($str);$j++) {
                        $arr[] = $str[$j];
                    }
                }
                $times=1;
                continue;
            }
            $times++;
        }
        $chars = $arr;
        return count($chars);
    }
}
```
```GO []
func compress(chars []byte) int {
    if len(chars)==0 {return -1}
    num, count, idx, times := 1, len(chars), 0, 0
    #字母计数  chars长度  下标索引  重塑数组次数
	for i:=0;i<count;i++ {
		if i == count-1 || chars[i+1] != chars[i]{
			chars[idx] = chars[i] // 添加字符
			idx++ // 索引自增
			times++ // 操作次数自增
			if num != 1 {
				tmp := []byte(strconv.Itoa(num)) // 将计数转换成byte
				for _,val := range tmp {
					chars[idx] = val // 添加计数数值'位'
					idx ++ // 索引自增
					times ++ // 操作次数自增
				}
			}
			num=1 // 重置字符计数
			continue
		}
		num++ // 字符计数自增
	}
	chars = chars[:times] // 切个到操作次数处
    return times
}
```
