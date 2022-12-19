时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String[] $cpdomains
     * @return String[]
     */
    function subdomainVisits($cpdomains) {
        $tmp = [];

        foreach ($cpdomains as $value) {
            list($nums, $domains) = explode(' ', $value);
            $domains = explode('.', $domains);
            $domain = '';
            for ($count = count($domains) - 1, $i = $count; $i >= 0; $i--) {
                $domain = $i == $count ? $domains[$i] : $domains[$i] . '.' . $domain;
                isset($tmp[$domain]) ? $tmp[$domain] += $nums : $tmp[$domain] = $nums;
            }
        }

        $array = [];

        foreach ($tmp as $key => $value) {
            $array[] = $value . ' ' . $key;
        }

        return $array;
    }
}
```