### 解题思路

看图就都懂了。

![WechatIMG418.png](https://pic.leetcode-cn.com/3d6983afdb923ed72c9d01c1d85ca15cae5a5cacd2afa19fc3d072ea0da403be-WechatIMG418.png)


### 代码

```php
class Solution
{

    /**
     * @param String $seq
     * @return Integer[]
     */
    public function maxDepthAfterSplit($seq)
    {
        $ans = [];
        $deep = -1;
        $seq = str_split($seq);
        foreach ($seq as $str) {
            if ($str === '(') {
                $deep++;
                array_push($ans, $deep % 2);
            }
            if ($str === ')') {
                array_push($ans, $deep % 2);
                $deep--;
            }
        }
        return $ans;
    }
}
```