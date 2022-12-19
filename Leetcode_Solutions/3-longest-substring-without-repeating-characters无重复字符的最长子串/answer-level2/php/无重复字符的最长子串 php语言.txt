思路：判断字符串中，是否出现重复字符，如果是，就取得长度后和最大值比较。然后对字符串初始化，进行下一次循环判断。

因为题目用例中没有涉及"dvdf"的场景，所以算法中，还有另一个场景的处理方式：通过字符串截取等运算，判断最大值。这个方式不适用于题目给出的用例，但是并不影响最终结果。

此算法效率尚可，击败 88% 用户。

```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $maxCount = 0;

        $_tmpStr = "";
        $count = strlen($s);

        for($i=0;$i<$count;$i++){
            $_cur = $s[$i];

            if(($lastPos = strpos($_tmpStr,$_cur)) !== false){ //最后一次出现的位置
                //针对用例：abcabcbb，bbbbb，pwwkew
                if(($tmpLength = strlen($_tmpStr)) > $maxCount){
                    $maxCount = $tmpLength;
                }
                
                //针对用例：dvdf。下面的处理方式，不适合上面的用例，但是因为上面已经记录最大长度，所以对最终结果也没有影响
                $firstStringLength = $lastPos + 1;//前面的字符串，只关心长度
                if($firstStringLength > $maxCount){
                    $maxCount = $firstStringLength;
                }

                //提取最后出现位置后面的字符
                $lastString = substr($_tmpStr,$firstStringLength);
                $_tmpStr = $lastString.$_cur;//初始化新字符串

                continue;
            }

            $_tmpStr .= $_cur;
        }

        //针对漏数据的处理
        if(($tmpLength = strlen($_tmpStr)) > $maxCount){
                $maxCount = $tmpLength;
        }

        return $maxCount;
    }
}
```
