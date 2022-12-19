### 解题思路
虽然可以用库函数实现，但我觉得不是这个题的本意。

下面是利用两次翻转实现的，第一次翻转整个句子，第二次翻转单词。

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        $start = 0;
        $end = strlen($s)-1;

        //句子翻转（第1次）
        $s = $this->swap($s);
        
        //删除空格
        while($s[$start] == " ") $start++;
        while($s[$end] == " ") $end--;
        
        //对单词进行翻转(第2次)
        $new_str = "";
        $tmp="";
        for($i=$start;$i<=$end;$i++){
            if($s[$i]==" "){
                if($s[$i-1] == " ") continue;
                $tmp = $this->swap($tmp);
                $tmp.=" ";
                $new_str.=$tmp;
                $tmp="";
            }else{
                $tmp.=$s[$i];
            }
        }
        //最后一个单词(因为最后一个单词没有空格，所以不会拼接到新字符串里，值还在tmp里)
        $last_word = $this->swap($tmp);
        
        return $new_str.$last_word;
    }

    /**
     * 对字符串进行翻转
     * @param $s
     * @return mixed
     */
    function swap($s){
        $i=0;
        $j=strlen($s)-1;
        while($i<$j){
            list($s[$i],$s[$j]) = [$s[$j],$s[$i]];
            $i++;
            $j--;
        }
        return $s;
    }
}
```