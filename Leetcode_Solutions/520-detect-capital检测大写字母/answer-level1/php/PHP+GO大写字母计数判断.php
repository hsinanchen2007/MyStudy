- 时间复杂度O(n),空间复杂度O(1)
- 先计算出大写字母个数
1. 一个字符
2. 一个大写字母并且第一个字母大写
3. 没有大写字母
4. 字符串个数和大写字母个数相同
以上4种都是为true的情况,剩下的都为false
```PHP []
class Solution {

    /**
     * @param String $word
     * @return Boolean
     */
    function detectCapitalUse($word) {
        $count = strlen($word);
        if ($count == 1) return true;
        $times = 0;
        for ($i=0;$i<$count;$i++) {
            if ($word[$i] <= 'Z'){
                $times++;
            }
        }
        if ($times==1 && $word[0] <= 'Z') return true;
        if ($times==0) return true;
        if ($times == $count) return true;
        return false;
    }
}
```
```GO []
func detectCapitalUse(word string) bool {
    count := len(word)
    if count == 1 {return true}
    t := 0
    for _,v := range word {
        if v <= 'Z' {
            t++
        }    
    }
    if t == 1 && word[0] <= 'Z' {return true}
    if t == 0 {return true}
    if t == count {return true}
    return false
}
```
