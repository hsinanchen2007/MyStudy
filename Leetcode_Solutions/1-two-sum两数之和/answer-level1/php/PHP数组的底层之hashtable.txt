### 解题思路

PHP中count()的时间负责度为O(1)，通过结构体中的一个值直接获取到数组的长度;
array_search()通过hashtable查找值，hashtable用于定值查找，其复杂度为O(1);
for循环遍历数组，数组内元素为n，故此时间复杂度为O(n);

额外使用了含有n个元素的数组new[]，故此空间复杂度为O(n);

最近刚开始研究数据结构和算法，不知道说的是否正确，见笑了。

PS： PHP中的数组，是广义上的数组，与数据结构中常说的数组(C语言中数组)，不是一回事。

在PHP中，数组不光是hashMap的实现，还实现了双向链表，所以既可以是索引数组也可以是关联数组，既可以快速查找也可以遍历，甚至还可以排序。

PHP中没有列表、字典、数组、Map、集合之分，就一个数组包含了所有的功能，用起来很方便，但底层实现相对复杂，印象中一个空数组的结构体要占96字节。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $count = count($nums);
        $new = [];
        for($i = 0; $i<$count; $i++){
            $result = array_search(($target-$nums[$i]), $new);
            if($result || $result === 0){
                return [$result, $i];
            }else{
                $new[$i] = $nums[$i];
            }
            
        }

    }
}
```