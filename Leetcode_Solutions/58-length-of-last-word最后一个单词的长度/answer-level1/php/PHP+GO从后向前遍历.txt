- 从后向前遍历字符串
- 末尾空格记得忽略
- 只统计第一次遇到的字符串即可
- Goland果然厉害
![image.png](https://pic.leetcode-cn.com/b49f96c357eac0dc109a8212e264605cadbcd8b3c600459d2d985dd6e3a68ff8-image.png)
```PHP []
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLastWord($s) {
        // 下面这一行,有点偷懒了,直接生对内置函数^_^ 请忽略下面这行
        // return strlen(array_pop(explode(' ',rtrim($s))));
        // 万恶的上面一行
        if (empty($s)) return 0;
        $count = strlen($s);
        $len = 0;
        for ($i=$count-1;$i>=0;$i--) {
            if ($s[$i] != ' ') {
                $len++;
            }
            if ($len !=0 && $s[$i] == ' ') {
                break;
            }
        }
        return $len;
    }
}
```
```GO []
# GO果然强大,执行效果比PHP快多了
func lengthOfLastWord(s string) int {
    if len(s) == 0 {return 0}
    count := len(s)
    out := 0
    for i := count - 1;i>=0;i--{
        if string(s[i]) != " "{
            out++
        }
        if out != 0 && string(s[i]) == " "{
            break
        }
    }
    return out
}
```
