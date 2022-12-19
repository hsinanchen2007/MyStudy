1. 将路径 `trim` 去掉两端 "/"
2. 将路径切分为数组
3. 遍历数组，为"" | "." 则跳过，为 ".." 时出栈栈顶元素，其他则直接入栈
4. "/" 拼接栈内数组，路径开始记得拼接根目录 "/"

``` php
class Solution {

    /**
     * @param String $path
     * @return String
     */
    function simplifyPath($path) {
    	$res = array();
        // 去右斜杠
        $path = trim($path,'/');
        // 遍历路径
        $pathArr = explode('/', $path);
        foreach ($pathArr as $key => $value) {
        	if ($value == '.' || $value == ''){
        		continue;
        	} else if  ($value == '..'){
				array_pop($res);
        	} else {
        		array_push($res,$value);
        	}
        }
        $resStr = '/' . implode('/', $res);
        // var_dump($res , $resStr);
        return $resStr;
    }
}
```
