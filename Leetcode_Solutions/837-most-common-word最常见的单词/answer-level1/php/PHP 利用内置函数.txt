### 解题思路
paragraph 只包含字母、空格和下列标点符号!?',;. 替换这些标点和特殊字符
将字符串分割为数组
将数组进行排序



### 代码

```php
class Solution {

    /**
     * @param String $paragraph
     * @param String[] $banned
     * @return String
     */
    function mostCommonWord($paragraph, $banned) {
        $paragraph = preg_replace( '/(\!|\?|\'|\,|\;|\.)/', ' ', $paragraph);
        $paragraph = array_count_values(explode(' ', strtolower($paragraph)));
        arsort($paragraph);
        foreach($paragraph as $key => $v){
            if($key && !in_array($key, $banned)){
                return $key;
            }
        }
    }
}
```

```php
#这是我第一次提交的代码。
#这么写的原因是我没有看到题目中已经指定只能使用哪种字符，在没看到这个条件时，我选择的是指取出英文字符
#然后将它拼成数组
#leetcode 不支持mb_serlen，所以只能自己模仿了一下，一来二去就慢了。
#并且看着也很乱，进步空间还很大
class Solution {

    /**
     * @param String $paragraph
     * @param String[] $banned
     * @return String
     */
    function mostCommonWord($paragraph, $banned) {
        $list = [];
        $str = '';
        $lenth = $this->mbstrlen($paragraph,"utf-8");
        for ($i=0;$i<$lenth;$i++){
            $v=preg_replace("/[^a-zA-Z]/iu",'',$paragraph[$i]);
            if (!is_null($v) && !empty($v)) {
                $v = strtolower($v);
                $str .= $v;
                if ($i+1==$lenth){
                    $list[] = $str;
                }
            } else {
                if ($str != '') {
                    $list[] = $str;
                }
                $str = '';
            }
        }

        $num = array_count_values($list);

        foreach ($banned as $k => $v) {
            if (isset($num[$v])) {
                unset($num[$v]);
            }
        }
        $max = 0;
        $key = '';
        foreach ($num as $k => $v) {

            if ($v > $max) {
                $max = $v;
                $key = $k;
            }
        }
        return $key;
    }
    function mbstrlen($str,$encoding="utf8")  {
        $step = $encoding=="utf8"?2:1;
        $count = 0;//字数
        $strlen = strlen($str);
        for($i=0;$i<$strlen;$i++){
            $count++;
            if(ord($str{$i})>=128){
                $i=$i+$step;
            }
        }
        return $count;
    }
}
```