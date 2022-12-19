### 解题思路
思路就是以数组最后一位开始判断0或1，若为0，则判断倒数第二位是否存在且为1，若倒数第二位为1则循环获得连续1的个数组成数组，判断奇偶数，奇数则false，偶数true；若为0，则为true。
短板：代码不够简化

### 代码

```php
class Solution {

    /**
     * @param Integer[] $bits
     * @return Boolean
     */
    function isOneBitCharacter($bits) {
        $result = 0;
        $temps = [];

        if (!empty($bits)) {
        	if ($bits[count($bits)-1] == 1) {
        	  return 0;
        	} else if (isset($bits[count($bits)-2])){
			  if ($bits[count($bits)-2] == 0) {
				  return 1;
	          } else {
	            for ($i = count($bits)-2 ; $i >= 0 ; $i-- ) {
	        	  if ($bits[$i] == 1) {
	        	    $temps[] = $bits[$i];continue;
	        	  } else {
	        	    break;
	        	  }
	            }
	           if (!empty($temps) && count($temps)%2 == 0) {
	               return 1;
	            } else {
	                return 0;
	            }
	          } 
        	} else {
        	  return 1;
        	}
        } else {
          return 0;
        }
    }
}
$a = new Solution();
$b = $a->isOneBitCharacter([1,0,0]);
```