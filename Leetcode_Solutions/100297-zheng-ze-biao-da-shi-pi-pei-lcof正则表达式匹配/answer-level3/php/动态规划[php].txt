### 解题思路
[具体思路见这位老哥的分享](https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/hui-su-dong-tai-gui-hua-by-ml-zimingmeng/)

我整理了PHP版本，并在代码中做了详细注释。

### 代码

```php
class Solution {

   /**
     * @param String $s
     * @param String $p
     * @return Boolean
     */
    function isMatch($s, $p) {
        //有s没有p，返回false
        if(empty($p) && !empty($s)) return false;
        //没有s，但是p有1个，比如. 肯定是false。两个的话比如.*就可能是true了
        if(empty($s) && strlen($p)==1) return false;

        //下面从1开始遍历，所以都加1
        $m = strlen($s)+1;
        $n = strlen($p)+1;

        //初始化，s的前0项与p的前0项肯定是true(匹配)
        $dp[0][0]=true;
        //初始化，s的前0项与p的前1项肯定是false(不匹配)
        $dp[0][1]=false;

        //继续初始化，像[ab,aa*]，直接把a*消掉，变为[ab,a]
        //之所以c=2，是因为要消掉 x*
        //下面总体的意思是，如果有x*，那么dp[0][c] = dp[x][c-2];
        for($c=2;$c<$n;$c++){
            $j = $c-1;
            if($p[$j]=="*"){
                $dp[0][$c]=$dp[0][$c-2];
            }
        }

        //开始匹配，从s一个个开始
        for($row=1;$row<$m;$row++){
            $i=$row-1;
            //对s的单个字符一个个进行p的匹配
            for($column=1;$column<$n;$column++){
                $j=$column-1;
                //如果s的第i个字符和p的第j个字符相等，或者p的第j个字符为.(什么都可以表示)
                //那么，dp本次的状态就等于上一次的状态
                if($s[$i] == $p[$j] || $p[$j]=="."){
                    $dp[$row][$column] = $dp[$row-1][$column-1];
                //如果p的第j个字符是*
                }elseif ($p[$j]=="*"){
                    //如果p的第j个字符是*，可以匹配0次或多次
                    //匹配了0次的话(代表把column的2个字符干掉了)，那么dp当前的状态就是column-2的状态
                    //匹配多次的话，代表这块没问题，那就拿$row后退一步的状态，这样就把匹配的多个的数量慢慢减少，就慢慢找到了状态
                    if($p[$j-1]==$s[$i] || $p[$j-1]=="."){
                        $dp[$row][$column] = $dp[$row-1][$column] || $dp[$row][$column-2];
                    //如果不相等的话，同样，匹配0次，直接干掉。那么dp当前的状态就是column-2的状态
                    }else{
                        $dp[$row][$column] = $dp[$row][$column-2];
                    }
                //所有情况都考虑了，那么剩下的情况就是false
                }else{
                    $dp[$row][$column]=false;
                }
            }
        }
        //$dp[$m][$n]代表s的前m项与p的前n项是否匹配，因为之前加过1，所以这里减1
        $res = $dp[$m-1][$n-1];
        if(is_null($res)) return false;
        return $res;
    }
}
```