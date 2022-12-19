### 解题思路
看了大佬的思路，我也是菜的一逼
我是通过explode分割函数来进行暴力匹配的
分为两个部分正向匹配和逆向匹配，就是str1去匹配str2，然后str2去匹配str1
先是用str1的第一个字符（逐增）去分割str2如果结果为全为空的数组(['','',''])就说明匹配上了，然后存入$this->zen这个全局数组例直到str2完整匹配结束
再是同样的步骤，只不过是str2来匹配str1，将结果存入$this->fan全局数组中，直到完整匹配结束

最后在反向匹配结束后进行处理得出结果
将zen或fan，通过从后往前的方式去除数组中的结果，判断另外一个全局数组中是否存在，存在说明就是最大公因数了....


### 代码

```php
class Solution {
    /**
     * @param String $str1
     * @param String $str2
     * @return String
     */
    function gcdOfStrings($str1, $str2) {
       $s2 = "";
        for ($i=0;$i<strlen($str2);$i++) {
			$s2 .= $str2[$i];
			$arr = explode($s2, $str1);
			//判断是否匹配
			if (isset($arr[1]) && $arr[1] === "" && $arr[count($arr) - 1] === "") {
				if (!$this->flag) {//$this->flag => flase表示正向匹配 true为反向
					$this->zen[] = $s2;
				} else {
					$this->fan[] = $s2;
				}
			}
		}
        //判断结果
        if ($this->flag){
			$zenNum = count($this->zen);
			//数组为空则表示无匹配
			if ($zenNum == 0 || count($this->fan) == 0) return "";
			//从后往前取出数据（因为是需要最大公因数）
			for ($i=$zenNum-1;$i<$zenNum;$i--){
				if (in_array($this->zen[$i], $this->fan)) return $this->zen[$i];
			}
		}
		$this->flag = true;
		//反向对比
		return $this->gcdOfStrings($str2, $str1);
    }
}
```