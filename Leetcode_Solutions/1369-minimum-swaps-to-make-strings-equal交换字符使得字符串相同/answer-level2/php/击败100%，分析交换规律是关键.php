### 解题思路
![微信截图_20200328095501.png](https://pic.leetcode-cn.com/d51a58022d4885ebc098d8fa20741e9affa6d5bcea00313a3d709073b2ed5e30-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200328095501.png)
看注释

### 代码

```php
class Solution {

    /**
     * @param String $s1
     * @param String $s2
     * @return Integer
     */
    function minimumSwap($s1, $s2) {
        $x_count = substr_count($s1.$s2,'x'); //x出现的总数
        if(($x_count%2) != 0) return -1; //x不是偶数返回-1
        $k = 0;
        $l = 0;
        for($i=0;$i<strlen($s1);$i++){
            if(substr($s1,$i,1) == substr($s2,$i,1)) continue;//相同匹配项
            if(substr($s1,$i,1) == 'x' ) $k++;//x对y数量
            if(substr($s1,$i,1) == 'y' ) $l++;//y对x数量
        }
        return (int)($k/2) + (int)($l/2) + ($k%2)*2;//分析了交换规律，$k中可一次交换就相同的配对有其一半，如果剩于一项必定与$l剩于一项进行二次交换。（也就是说二次交换才能相同的情况最多只有一组）
    }
}
```