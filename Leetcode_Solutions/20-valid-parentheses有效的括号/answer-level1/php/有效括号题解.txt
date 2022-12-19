### 解题思路
栈
遍历字符串，左括号入栈，右扩号，判断栈的最后一个元素是否能配对，如果能则pop出去，不能 则返回false

长度是基数肯定是false
第一个字符是右括号肯定是false

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        
        $arr = array(
            '(' => ')',
            '{' => '}',
            '[' => ']'
        );
        $len = strlen( $s );
        $stack = array();
        if( $len % 2 == 1 ) return false;
        if( !$arr[ $s[0] ] ) return false ;

        for( $i = 0 ; $i < $len ; $i ++ ) {

            if( $arr[ $s[$i] ] ) {
                $stack[] = $s[$i];
            }else{
                $tail = array_pop( $stack );
                if( $arr[$tail] != $s[$i] ) return false;
                
            }
        }
        return count( $stack ) == 0 ;
    }
}
```