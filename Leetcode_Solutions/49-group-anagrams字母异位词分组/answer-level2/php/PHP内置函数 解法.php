参考异位词 解法 https://leetcode-cn.com/problems/valid-anagram/solution/phpnei-zhi-zi-fu-chuan-han-shu-ji-bai-99-by-user85/


```
class Solution {

        /**
         * @param String[] $strs
         * @return String[][]
         */
        function groupAnagrams($strs) {
            
            $map = [];
            
            foreach($strs as $str){
                $map[implode(',', array_keys(count_chars($str, 1)))][] = $str;
            }
    
            return array_values($map);
        }
    }
```
