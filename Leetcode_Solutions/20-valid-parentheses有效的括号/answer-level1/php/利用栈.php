### 解题思路
利用栈，为空就push，不为空就对比栈顶字符与当前字符是否可以配对

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $length = strlen($s);
        $arr = [];
        $count = 0;
        for ($i=0; $i < $length; $i++) { 
        	$b = substr($s, $i, 1);
        	if ($count == 0) {
        		$arr[] = $b;
        		$count++;
        	} else {
        		$check = array_pop($arr);
        		if ( ($check == "(" && $b == ')') || ($check == "[" && $b == ']') || ($check == "{" && $b == '}') ) {
        			$count--;
        		} else {
        			$arr[] = $check;
        			$arr[] = $b;
        			$count++;
        		}
        	}

        }
        return count($arr) ? false : true;
    }
}
```