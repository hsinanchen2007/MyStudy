![微信截图_20191031194620.png](https://pic.leetcode-cn.com/c0868807f39580bb1c2a5ec03eed76423292aca443924fefd6bb7c8897e2aef8-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191031194620.png)

```
function findRepeatedDnaSequences($s) {
    if(strlen($s)<=10) return [];
    $left = 0;
    $right = 9;
    $map = [];
    $ans = [];
    while($right < strlen($s)){
        $key = substr($s,$left,10);
        $map[$key] = isset($map[$key])?$map[$key]+1:1;
        if($map[$key]==2) $ans[] = $key;
        $left++;
        $right++;
    }
    return $ans;
}
```
