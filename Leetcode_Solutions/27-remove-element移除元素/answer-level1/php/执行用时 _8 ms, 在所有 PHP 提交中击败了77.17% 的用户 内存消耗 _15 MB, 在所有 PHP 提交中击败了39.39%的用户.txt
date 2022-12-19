### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $val
     * @return Integer
     */
    function removeElement(&$nums, $val) {
        //第一种解法，执行用时8ms：内存消耗15M
        $count = count($nums);//定义一个变量，并统计数组长度
        for($i=0;$i<$count;$i++){
            if($nums[$i] == $val){
                unset($nums[$i]);//利用循环找到相同元素并删除
            }
        }
        return count($nums);//输出删除完数组的长度

        // 第二种解法，执行用时12ms：内存消耗15.1M
        foreach($nums as $key => $value){
            if($value == $val){
                unset($nums[$key]);//遍历数组，找到相同元素并删除
            }
        }
        return count($nums);//输出删除完数组的长度
        
    }
}
```