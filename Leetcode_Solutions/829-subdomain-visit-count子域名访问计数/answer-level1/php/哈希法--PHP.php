### 解题思路
很直观的想法，把域名分隔，存在map中，记数。

### 算法


### 代码

```php
class Solution {

    /**
     * @param String[] $cpdomains
     * @return String[]
     */
    function subdomainVisits($cpdomains) {
        $maps = [];
        
        for ($i = 0; $i < count($cpdomains); $i++) {
            list($count, $domain) = explode(' ', $cpdomains[$i]);
            $sub_domains = explode('.', $domain);
            $cur = '';
            // 从后往前拼接子域名
            for ($j = count($sub_domains) - 1; $j >= 0; $j--) {
                $cur = $sub_domains[$j] . ($j < count($sub_domains) - 1 ? '.' : '') . $cur;
                $maps[$cur] += $count;
            }
        }

        $res = [];
        foreach ($maps as $k => $c) {
                $res[] = "$c $k";
        }

        return $res;
    }
}
```

### 参考
[leetcode](https://leetcode-cn.com/problems/subdomain-visit-count/solution/zi-yu-ming-fang-wen-ji-shu-by-leetcode/)