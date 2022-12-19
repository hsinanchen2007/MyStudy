### 解题思路
![微信图片_20200313214543.png](https://pic.leetcode-cn.com/932c39043afb028d8c8dfffc6a79f5b219a95a1284ad0f3198744074328f54c2-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200313214543.png)
php解题如下

### 代码

```php
class Solution {

    function majorityElement($nums) {
        $conut = count($nums);
        $out_nums = [];

        for ($i = 0; $i < $conut; $i++) {
            if (in_array($nums[$i],$out_nums)){continue;}
            
            if (count(array_keys($nums,$nums[$i])) > $conut/2)
                return $nums[$i];
            else
                $out_nums[] = $nums[$i];
        }
    }
}
```