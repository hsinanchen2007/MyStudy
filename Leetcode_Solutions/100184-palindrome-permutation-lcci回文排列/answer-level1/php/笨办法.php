### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function canPermutePalindrome($s) {
        // 分割数组
        $se = str_split($s);
        // 定义奇数数量为0
        $k = 0;
        // 定义计算过的字符的数组 刚开始我空
        $ar = array();
        foreach($se as $key=>$val)
        {
            // 判断字符是否在计算过的数组里 不在进行统计 
            if(!in_array($val,$ar))
            {
                // 统计出现的次数 奇数$k +1 超过1 返回false
                $zhi = substr_count($s,$val);
                if($zhi%2 == 1)
                {
                    $k += 1;
                    if($k > 1)
                    {
                        return false;
                    }
                }
                $ar[] = $val;
            }
        }
        return true;
    }
}
```