### 解题思路

     这个解决思路是直接去 执行替换操作，和 查找问题索引 ：查找并计数；差不多，只是换了个思路
	 思路：去执行替换 并计数；从理解的角度，这种更容易，
	 Code via @flyingrain

	 和官方解题的 方式一，基本相同  "总时间复杂度为 O(N^2) "可以理解为，仅执行操作A，循环检查与执行2遍。
	 有空再去看看 其他人的解决思路，例如官方的解题的方法二、三
	 
	 之前摄像就是 用 方法三  查找问题索引 的方式，但是有个逻辑忽略了简单的路径"A[p-1], A[p], A[p+1], A[p+2] 都存在的  2中可能" 思考过，但是并没有去尝试这样写，硬用"A[p-1], A[p], A[p+1]"套逻辑尝试解决....被复杂化了
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */


    function checkPossibility($nums) {
        $count=0;
		 for($i= 0;$i<count($nums)-1;$i++){
			//echo $i."次: A:".$nums[$i-1]." B: ".$nums[$i]." C: ".$nums[$i+1];
			//echo "----</br>";
			if($nums[$i] > $nums[$i+1]){
				if($i== 0 || $nums[$i-1]<=$nums[$i+1]){
					$nums[$i] = $nums[$i+1];
					//echo $i."A操作: A:".$nums[$i-1]." B: ".$nums[$i]." C: ".$nums[$i+1];
					//echo "----</br>";
				}else{
					//echo $i."B操作: A:".$nums[$i-1]." B: ".$nums[$i]." C: ".$nums[$i+1];
					//echo "----</br>";
					 $nums[$i+1] = $nums[$i];
				}
				$count++;
				if($count == 2){
				 return false;
				}               
			}
		}
         return true;
    }
    
}
```