### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s1
     * @param String $s2
     * @return Boolean
     */
   function CheckPermutation($s1, $s2) {
        //消消乐
        $i = 0;
        if(strlen($s1)!=strlen($s2))
        {
            return false;
			
        }
	 
        while($i<strlen($s1))
        {
			
            $count = strrpos($s2,$s1[$i]);
            $s2=substr_replace($s2,"",$count,1);
		
            if ($count===false)
            {
				
                return false;
            }
		
            $i++;
        }
        return true;



    }
}
```