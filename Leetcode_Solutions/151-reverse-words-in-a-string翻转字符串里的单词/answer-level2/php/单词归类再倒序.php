### 解题思路
遍历原字符串，根据空格符分隔，把相连的字符塞进同一个数组，然后倒序总数组
![image.png](https://pic.leetcode-cn.com/98b1c4dc620e490c4cb3043ab82f44cec6bd7fe43704f6b574336fe16319c50d-image.png)

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        $map = [];
    	$s = trim($s);
    	$j = 0;
    	for ($i=0; $i < strlen($s); $i++) { 
    		if ($s[$i] == ' ') {
    			$j += 1; //放单词的数组序号
    			continue;
    		}
    		$map[$j] = (isset($map[$j]) ? $map[$j] : '' ).$s[$i];
    	}
    	krsort($map);
    	$map = implode(' ', $map);
    	return $map;
    }
}
```