使用 strrev() 反转
```
class Solution
{
    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) 
    {
        if ($x < 0 || $x - strrev($x) != 0) return false;   
        return true;
    }
}
```
使用数学计算反转
```
class Solution
{
    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) 
    {
        if ($x < 0 || $x - $this->i***ev($x) != 0) return false;   
        return true;
    }
    
    /**
     * @param integer $int
     * @return int
     */
    function i***ev($int)
    {
        $rev = 0;
        while ($int >= 1) {
            $pop = $int % 10;
            $int /= 10;
            
            $rev = $rev * 10 + $pop;
        }
        
        return $rev;
    }
}
```