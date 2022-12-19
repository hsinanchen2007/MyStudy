思路：
1. 先获取字符串长度
2. 判断第一个字符是否是运算符，如果是截取保存，整体字符串去除运算符
3. 判断末尾字符是否未0，如果是进行排除，排除一次可减少for运行次数 
4. 判断第二步获取的运算符是否是‘-’如果是进行拼接
5. 判断得到的字符串是否大于数值范围如果是，将字符串赋值为0
6. 返回值将字符串强转int，排除第3不末尾有多个0情况
```
class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $len = strlen($x);
        $str = '';
        $max = pow(2,31)-1;
        $min = pow(-2,31);
        $s = '+';
        if(substr($x,0,1) == '-' || substr($x,0,1) == '+'){
        	$s = substr($x,0,1);
			$x = substr($x,1,$len-1);
		}
		$len = strlen($x);
	if(substr($x,-1,1) == '0'){
		$x = substr($x,0,$len-1);
		$len = strlen($x);
		if($len < 1){
			$x = '0';
			$len = 1;
		}
	}
		
        for($i=$len;$i>0;$i--)
        {
            $str .= substr($x,$i-1,1);
        }
        if($s == '-'){
		$str = $s.$str;
	}
	if($str < $min){
		$str = '0';
	}else if($str > $max){
		$str = '0';
	}
        return (int)$str;
    }
}
```