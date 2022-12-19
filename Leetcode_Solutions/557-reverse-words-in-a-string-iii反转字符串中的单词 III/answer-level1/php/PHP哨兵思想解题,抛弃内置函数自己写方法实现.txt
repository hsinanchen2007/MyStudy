PHP的内置函数确实可以很快速很简单的处理这个问题,例如strrev,但是本着做算法要抛弃内置函数辅助的原则自己写了一个
- 空格标志位
- 注意最后字符串边界
- 注意空格补充
- 时间复杂度O(2n),空间复杂度O(n)
```
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        if (empty($s)) {
            return '';
        }
        $out = '';
        $count = strlen($s);
        $kong = 0; // 空格标志位(可以理解为哨兵)
        # 遍历字符串
        for ($i=0;$i<$count;$i++) {
            # 寻找空格和最后字符串
            if ($s[$i]==' ' || $i==$count-1) {
                # 遍历上个空格到该空格中间字符串
                for ($j=$i;$j>=$kong;$j--) {
                    if ($s[$j] != ' ') {
                        $out .= $s[$j];
                    }
                }
                # 填补空格(注意末尾的边界判断)
                if ($i!=$count-1) {
                    $out .= ' ';
                }
                # 修改哨兵位置
                $kong = $i;
            }
        }
        return $out;
    }
}
```
- strrev内置函数在用C语言实现时,首先申请了一块与字符串一样长度的内存空间
- 再将源字符串倒叙的每个字符地址,正序赋予新申请的内存地址上,返回新的字符串
- 下图为PHP7.1.1版本strrev函数实现
![image.png](https://pic.leetcode-cn.com/f5d96821ea902d6420946547426cf7f647ea3c3b33647b81c9bda9d46d7e48af-image.png)
