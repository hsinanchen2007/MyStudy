# 思路
1.循环字符串,判断空格
2.利用explode函数一步到位
*你们这么聪明,第二种方法,应该都知道,我就贴第一种方法的代码,我们互相交流下(*￣︶￣)*
```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLastWord($s) {
            $s = trim($s,' ');
            $len = strlen($s);
            if ($s == '') {
                return 0;
            }
            if (count(explode(' ',$s)) == 1) {
                return $len;
            }
            $num = 0;
            for ($i = $len - 1; $i >= 0; $i--) {
                if ($s[$i] == ' ') {
                    return $num;
                } else {
                    $num++;
                }
            }
        }
}
```
# 备注:大哥们,随便批评啊,不要吝啬,你们的评论是我前进的动力,让我成长(发这个解题,只是看PHP的解题太少了,支持一下PHP)
*我不是标题党*
![微信图片_20190930142804.png](https://pic.leetcode-cn.com/55f5eb983139a421a13e653e1839fd70cee5fc61569b6becb09c548cbd0f0352-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190930142804.png)

