# [THINKING]
- 倒叙遍历法
    - 其实我们只需要最后一个字符串的长度
    - 那么如何判断是最后一个字符串呢，只要从后向前遍历，遇到空格或者是已经到头；
    - 但是考虑到，最后一个字符串不一定是字母，也有可能是空格，所以要掠过这些，例如"I am student   "
    - 我们用一个count来进行记录最后一个字符串的长度
    - 进行倒叙遍历
    - 如果字符串为空，那么直接返回0 【边界判断】
    - 如果当前遍历的是空格，而且count=0，那么就可能是这样的情况 "I am "，正在遍历最后的空格
        - 那就不做操作继续循环
    - 如果当前遍历的不是空格，而是字母
        - 那就++count
    - 如果当前遍历是空格，而且count!=0  那么表明最后一个字符串已经遍历完毕
        - 那么直接break然后返回count的值
    - 如果循环正常结束，没有经过break，那么count也是在一直记录着，例如"helloworld  "
        - 最终count记录这个字母字符串的长度，也就是"helloworld"
- 函数法
    - 先用 trim() 去除字符串前后空格
    - 看到这个题估计大多数都会选择PHP的 explode() 函数 把字符串按照空格拆成数组
    - 然后直接使用 array_pop() 弹出数组栈顶的元素字符串
    - 然后使用 strlen() 计算字符串长度

- 函数说明
    - trim — 去除字符串首尾处的空白字符（或者其他字符）
        - trim ( string $str [, string $character_mask = " \t\n\r\0\x0B" ] ) : string
        - 此函数返回字符串 str 去除首尾空白字符后的结果。
        - 如果不指定第二个参数，trim() 将去除这些字符
            - 普通空格符" "
            - 制表符    "\t"
            - 换行符    "\n"
            - 回车符    "\r"
            - 空字节符   "\0"
            - 垂直制表符
    - array_pop — 弹出并返回 array 数组的最后一个单元，并将数组 array 的长度减一。
        - array_pop ( array &$array ) : mixed  【注意是引用类型参数】
        - 使用此函数后会重置（reset()）array 指针。
    - explode — 使用一个字符串分割另一个字符串
        - explode ( string $delimiter , string $string [, int $limit ] ) : array
        - 此函数返回由字符串组成的数组，每个元素都是 string 的一个子串，它们被字符串 delimiter 作为边界点分割出来。
    - strlen — 返回给定的字符串 string 的长度。
        - strlen ( string $string ) : int
        - 成功则返回字符串 string 的长度；如果 string 为空，则返回 0。


# [CODING]
```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
     // 倒叙遍历法
     // 执行用时 :8 ms, 在所有 php 提交中击败了64.83%的用户
     // 内存消耗 :15 MB, 在所有 php 提交中击败了10.29%的用户
    function lengthOfLastWord($s) {
         $len   = strlen($s); // 获取字符串长度
         $count = 0;
         for($i=$len-1; $i>=0; $i-- ) {
             if($s[$i] != ' ') {
                 ++$count; // 最后一个字符串长度计算
             }
             if($s[$i] == ' ' && $count!=0 ) {
                 break; // 如果遍历的当前是 空格 而且count已经计数，就是已经遍历过最后一个字符串
             }
             // 如果遍历的当前是空格，而且count还没有计数，那么表明正在遍历末尾的空格，例如 "hello  world     "
         }// 如果遍历到最后，也就是没有break，那么表明字符串应该是一整个例如 "helloworld  "
         return $count;
    }

      // 函数法
      // 使用中间变量
      // 执行用时 :12 ms, 在所有 php 提交中击败了26.21%的用户
      // 内存消耗 :15.2 MB, 在所有 php 提交中击败了10.29%的用户
      // 不使用中间变量
      // 执行用时 :4 ms, 在所有 php 提交中击败了91.72%的用户
      // 内存消耗 :15.1 MB, 在所有 php 提交中击败了10.29%的用户
     function lengthOfLastWord2($s) {
            // 这里分成了三个语句，因为array_pop要传入引用参数
           // $arr= explode(' ',trim($s));
           // $re = array_pop($arr);
           // return strlen($re);
           // 如果改成下面的  PHP7.2 报错Notice: Only variables should be passed by reference
           return strlen(array_pop(explode(' ',trim($s))));
     }
}


$obj    = new Solution();
$s      = "This is leetcode ";
$re     = $obj->lengthOfLastWord2($s);
var_dump($re);

```
