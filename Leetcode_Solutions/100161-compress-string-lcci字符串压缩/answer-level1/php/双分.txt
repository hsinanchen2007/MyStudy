### 解题思路
把新字串的每个字母和其数量分离，之后再合并

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function compressString($S) {
        $size = strlen($S);
        if($size < 3) return $S;//长度小于3则返回

        $new_str = "";
        $cur_char = $S[0];//当前字母
        $cur_count = 1;//当前字母数量
        for($i=1;$i<$size;$i++){
            if($S[$i] == $S[$i-1]){
                $cur_count++; //跟上个字母相同则数量加一
            }
            else{
                $new_str .= $cur_char . $cur_count;//跟上个字母不同，把之前的结果加入最终结果
                $cur_char = $S[$i];
                $cur_count = 1;
            }

        }

        $new_str .= $cur_char . $cur_count;//循环结束时还有没有加入的字母

        return strlen($new_str) > $size ? $S:$new_str;

    }
}
```