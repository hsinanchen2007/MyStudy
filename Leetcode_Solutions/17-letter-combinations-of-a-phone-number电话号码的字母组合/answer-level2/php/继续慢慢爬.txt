### 解题思路
感谢[@ruan-shao-xiang](/u/ruan-shao-xiang/)的简洁明了的解释，比回溯法好理解且容易读懂的多

### 代码

```php
class Solution {

    /**
     * @param String $digits
     * @return String[]
     */
    function letterCombinations($digits) {  
        if (empty($digits)) {
            return [];
        }

        // 先创建字典
        $dic = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"];

        // 创建一个用于模拟队列的数组
        $resultList = [''];

        // 循环输入$digits
        echo "DI: $digits -- ";
        for ($i=0; $i < strlen($digits); $i++) {
            //current digit
            $cur_digit = $digits[$i];
            echo "Cur digit: " . $cur_digit . " | ";

            //execute while the first element from the current end result
            //has the same size as the current for loop index value
            while (strlen($resultList[0]) == $i) {
                echo " CUR len: " . strlen($resultList[0]) . " CUR ind: " . $i;
                //first element of the array
                //to be appended to any smaller sized elements
                $head = array_shift($resultList);
                echo " Appending digit: $head | ";

                //all possible letters from the current digit
                $chars = $dic[$cur_digit];
                echo " CHARS: $str |";

                //append all combos to the final reuslt
                for ($j=0; $j < strlen($chars); $j++) {
                    $resultList[] = $head.$chars[$j];
                }

                //current final result
                print_r($resultList);
            }

        }

        return $resultList;

    }

}
```