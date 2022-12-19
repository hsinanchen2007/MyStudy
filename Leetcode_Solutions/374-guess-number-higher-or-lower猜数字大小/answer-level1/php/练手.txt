### 解题思路
此处撰写解题思路

### 代码

```php
/** 
 * The API guess is defined in the parent class.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * public function guess($num){}
 */

class Solution extends GuessGame {
    /**
     * @param  Integer  $n
     * @return Integer
     */
    function guessNumber($n) {
        
        $lower = 1;
        $height = $n;
        for($i=1;$i<=$n;$i++)
        {
            $middle = intval(($height+$lower)/2);

            if($this->guess($middle)===0)
            {
                return $middle;
            }
            if($this->guess($middle)==1)
            {
                 $lower = $middle+1;   
            }
             if($this->guess($middle)==-1)
            {
                 $height = $middle-1;   
            }
        
        }
        

    }
    
}
```