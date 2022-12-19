### 解题思路
先将数组字符串化，再自定义字符串比较函数作为排序方法，将排序后的字符串进行拼接即可获得答案。

### 代码

```php
class Solution {

    /**
    * 对比两个字符串大小
    */
    function cmpStr($x,$y)
    {
        return $x.$y>$y.$x;
    }
    /**
     * @param Integer[] $nums
     * @return String
     */
    function largestNumber($nums) {
        $strArr = array_map('strval',$nums);
        //使用用户自定义比较方法进行排序
        usort($strArr,['Solution','cmpStr']);
        //因为默认是从小到大排序的，所以使用反向连接，将小的接到后边
        $result = '';
        foreach($strArr as $str)
        {
            $result=$str.$result;
        }
        //如果结果是以0开头的，则只返回一个0
        if(strpos($result,'0')===0){
            $result = '0';
        }
        return $result;
    }
}
```