```
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    public function isPalindrome($s) 
    {
        //1.过滤字符串
        $filterString = $this->filterString($s);
        //2.反转字符串 
        //3.比较
        return strtolower(strrev($filterString)) == strtolower($filterString);
    }

    /**
     * @param $s string
     */
    private function filterString($s) 
    {
        preg_match_all('/[\x{4e00}-\x{9fa5}a-zA-Z0-9]/u',$s,$result);
        $temp =join('',$result[0]);
        return $temp;
    }
}
```
