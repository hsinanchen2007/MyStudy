# 方法一：使用PHP原生的方法 str_replace；
```
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function replaceSpace($s) {
       return str_replace(' ', '%20', $s);
    }
}
```

# 方法二：剑指上面推荐的方法
```
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function replaceSpace($s) {
        $space = 0;
        $len = strlen($s);
        for ($i = 0; $i < $len; $i++) {
            if ($s[$i] == ' ') {
                $space++;
            }
        }

        $oldLen = $len;
        $newLen = strlen($s) + $space * 2;

        $newStr = '';
        while ($oldLen >= 0) {
            if ($s[$oldLen] == ' ') {
                $newStr[$newLen--] = '0';
                $newStr[$newLen--] = '2';
                $newStr[$newLen--] = '%';
            } else {
                $newStr[$newLen--] = $s[$oldLen];
            }
            $oldLen--;
        } 
        return $newStr;
    }
}
```
