### 解题思路
感谢[@nettee](/u/nettee/)的题解，比字典树更易理解且更有效率。
简单来说就是如果一个**字串A**可以包含在另外一个**字串B**中，那说明这个字串B的后缀跟A相同，那也就是说如果把字串反向排列，他们的开头都一样，这样就可以简单排序，例如：
**["time","me","bell"]**
反转+排序后为
**["em","emit","lleb"]**

这样历遍一次新的字串组，把所有包含在其他字串中的字串删除，最后中间加"#"的总长度即为答案。

### 代码

```php
class Solution {

    /**
     * @param String[] $words
     * @return Integer
     */
    function minimumLengthEncoding($words) {
        //把原字串组反转
        for($i=0;$i<count($words);$i++){
            $words[$i] = strrev($words[$i]);
        }

        sort($words);//把反向字串组排序

        $total_len = 0;
        for ($i = 0; $i < count($words); $i++) {
            //需要加$i < count($words)因为否则有可能出现字串组中全都是一样的字串，最后返回总长度0
            //加上之后至少会保留一个字串
            if ($i< count($words) && strstr($words[$i+1],$words[$i])) {
                continue;
            } else {
                $total_len += strlen($words[$i]) + 1; // 字串尾加一个“#”
            }
        }
        return $total_len;

    }
}
```