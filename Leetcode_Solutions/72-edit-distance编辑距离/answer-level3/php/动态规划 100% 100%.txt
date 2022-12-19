### 解题思路
感谢[@labuladong](/u/labuladong/)的解答，终于更加清晰地理解动态规划的原理了。

### 代码

```php
class Solution {

    /**
     * @param String $word1
     * @param String $word2
     * @return Integer
     */

    private $w1;
    private $w2;
    private $memo = [];//设置字典，储存计算过的结果

    function minDistance($word1, $word2) {
        $this->w1 = $word1;//把传入字串转为内部字串供动规函数使用
        $this->w2 = $word2;
        return $this->calc(strlen($word1)-1, strlen($word2)-1);
    }

    function calc($char_pos1, $char_pos2) {
        //一方已经历遍完毕，只需要把未结束一方剩余字串长度返回
        if ($char_pos1 == -1) return $char_pos2+1;
        elseif ($char_pos2 == -1) return $char_pos1+1;

        //查询字典，如有结果直接返回
        if (isset($this->memo[$char_pos1][$char_pos2])) {
            return $this->memo[$char_pos1][$char_pos2];
        }
        
        //相同位置相同字母，跳过
        if ($this->w1[$char_pos1] == $this->w2[$char_pos2]) {
            $this->memo[$char_pos1][$char_pos2] = $this->calc($char_pos1-1, $char_pos2-1);
        } else {
            //找到插入，删除，或者替换所造成结果的最小值
            $this->memo[$char_pos1][$char_pos2] = min(
                //所有一下三个步骤都需要+1，因为走了一步
                //插入字符，等于是把第二个字串位置提前一格
                $this->calc($char_pos1, $char_pos2-1)+1,
                //删除字符，等于是第一个字串的位置提前一个
                $this->calc($char_pos1-1, $char_pos2)+1,
                //替换字符，两者皆前走一格
                $this->calc($char_pos1-1, $char_pos2-1)+1
            );
        }

        return $this->memo[$char_pos1][$char_pos2];
    }
}
```