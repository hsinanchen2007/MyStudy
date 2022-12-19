**题目意思：** 
给定一个合格的括号字符串，将其分解成两个字串a和b，使得max(a串的嵌套深度,b串的嵌套深度) 最小； 
比如输入的括号字符串嵌套深度是3，希望通过分离后max(a,b)能达到1最好，意思是最小的嵌套深度了。
**思路：**
目的就是为了让两个的栈深差不多小，所以！只需要平均分配左括号就可以了，因为在输入中左括号就基本就是
栈的深度了，所以根据奇偶平均分配给俩串，就能得到比较小的栈深

**代码：**
```
function maxDepthAfterSplit($seq) {
    $ans = [];
    $deep = 0;
    for ($i=0; $i < strlen($seq); $i++) { 
    	if ($seq[$i] == '(') {
    		$deep += 1 ;
    		$ans[] = $deep % 2; 
    	}elseif ($seq[$i] == ')') {
    		$ans[] = $deep % 2;
    		$deep -= 1;
    	}
    }
    return $ans;
}

print_r(maxDepthAfterSplit("()(())()"));
```
