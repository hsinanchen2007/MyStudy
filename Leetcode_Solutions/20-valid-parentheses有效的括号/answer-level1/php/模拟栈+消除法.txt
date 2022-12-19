# [THINKING]
- 模拟栈
    - 左右括号要匹配，那么肯定要是偶数，所以一开始先判断字符串长度，如果是奇数直接返回。【边界判断】
    - 利用栈的特性，先进后出；
    - 初始化一个栈stack；
    - 遍历整个表达式；
    - 如果是左括号，那么压入栈stack，等待稍后处理；
    - 如果是右括号，那么我们检查栈顶的元素，是否匹配对应的右括号，如果匹配，那么弹出；如果不匹配，压入栈中继续向后匹配；
    - 如果整个遍历完之后，栈中还有元素，那么我们判断是无效的表达式；
    - 时间复杂度 O(N)：遍历整个字符串；
    - 空间复杂度 O(N)：哈希表和栈使用线性的空间大小。
 - 消除法
    - 由于需要进行括号匹配，有效的表达式，那么中间一定右左右括号挨着的，
    - 我们不断循环遍历，找到中间() {} [] 这样的字符，然后替换为''
    - 最后一定可以消除，但是相对来说，没有第一种快
    - 有点类似我们玩的消消乐；
- php相关函数
    - array_push — 将一个或多个单元压入数组的末尾（入栈）
    - end — 将数组的内部指针指向最后一个单元
    - array_pop — 弹出数组最后一个单元（出栈） 使用此函数后会重置（reset()）array 指针。
    - str_replace ( mixed $search , mixed $replace , mixed $subject [, int &$count ] ) : mixed
        - 该函数返回一个字符串或者数组。该字符串或数组是将 subject 中全部的 search 都被 replace 替换之后的结果。

# [CODING]
```
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
     // 栈
     // 执行用时 :8 ms, 在所有 php 提交中击败了75.71%的用户
     // 内存消耗 :15.2 MB, 在所有 php 提交中击了35.37%的用户
    function isValid($s) {
        $stack = []; // 模拟栈
        // 使用哈希来对应 左右括号的关系
        $map   = ['{'=>'}','['=>']','('=>')',')'=>'(',']'=>'[','}'=>'{']; // 左右括号对应
        $lMap  = ['{'=>1,'['=>1,'('=>1]; // 左括号
        $rMap  = ['}'=>1,']'=>1,')'=>1]; // 右括号
        $len   = strlen($s); // 字符串的长度
        // 如果是奇数直接返回
        if($len%2 != 0) return false;
        for($i=0; $i<$len; $i++){
             if( isset($lMap[$s[$i]]) ) {// 如果是是左括号，就压栈
                 array_push($stack, $s[$i]);
             }elseif( isset($rMap[$s[$i]]) ){// 如果是右括号
                 if($s[$i] == $map[end($stack)]){
                     array_pop($stack); // 弹出数组末尾，也就是栈顶元素
                 }else{
                     array_push($stack, $s[$i]);// 如果不匹配，也压栈
                 }
             }
        }
        if(empty($stack)){
            return true; // 最终都匹配成功
        }else{
            return false;
        }
    }

    // 栈
    // 由于第一个，用了太多哈希数组，不过思路还行，实际上还能简化一版
    // 执行用时 :8 ms, 在所有 php 提交中击败了75.71%的用户
    // 内存消耗 :15.2 MB, 在所有 php 提交中击败了35.37%的用户
    function isValid2($s) {
        $stack = []; // 模拟栈
        // 使用哈希来对应 左右括号的关系(只用一个哈希表就行)
        $map   = [')'=>'(',']'=>'[','}'=>'{']; // 右 匹配 左
        $len   = strlen($s); // 字符串的长度
        // 如果是奇数直接返回
        if($len%2 != 0) return false;
        for($i=0; $i<$len; $i++){
             if( !isset($map[$s[$i]]) ) {// 如果是是左括号，就压栈
                 array_push($stack, $s[$i]);
             }else{// 如果是右括号
                 $tmp = array_pop($stack); // 弹出栈顶元素
                 if( $tmp != $map[$s[$i]]){ // 如果不匹配的，就直接给出false
                     return false; // 提前终止
                 }
             }
        }
       // 使用三元运算符
        return $stack ? false : true;
    }

    // 消除法
    // 执行用时 :44 ms, 在所有 php 提交中击败了15.09%的用户
    // 内存消耗 :15 MB, 在所有 php 提交中击败了41.46%的用户
    function isValid3($s) {
        $len   = strlen($s);
        // 如果是奇数直接返回,边界判断，提前终止
        if($len%2 != 0) return false;
        while(true){
         $s = str_replace(['()','[]','{}'],'',$s,$count); // 本次替换的 次数
         // 如果没有可以替换的 那么就判断是否为空，然后结束
         if($count==0){
             return strlen($s)==0;
         }
       }
    }

}

$obj = new Solution();
$s   = "((";
$re  = $obj->isValid2($s); // 方法2 最快
var_dump($re);

```
