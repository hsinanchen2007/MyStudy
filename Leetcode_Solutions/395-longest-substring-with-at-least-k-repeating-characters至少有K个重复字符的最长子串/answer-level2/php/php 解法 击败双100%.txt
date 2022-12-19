![微信截图_20191030214443.png](https://pic.leetcode-cn.com/af52cff6ff343f631240bb30707c59b25417581447c891e3cdac1eabb6de0fa4-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191030214443.png)

```
function longestSubstring($s, $k) {
    $n = strlen($s);
    if($k<=1) return $n;
    if($n==0 || $k>$n) return 0;
    $map = [];
    for($i=0;$i<$n;$i++)
        $map[$s[$i]] = isset($map[$s[$i]])?$map[$s[$i]]+1:1;
    $j=0;
    while($j < $n && $map[$s[$j]] >= $k) $j++;
    if($j == $n) return $n;
    $left = $this->longestSubstring(substr($s,0,$j),$k);
    while($j < $n && $map[$s[$j]] < $k) $j++;
    $right = $this->longestSubstring(substr($s,$j),$k);
    return max($left,$right);
}
```
