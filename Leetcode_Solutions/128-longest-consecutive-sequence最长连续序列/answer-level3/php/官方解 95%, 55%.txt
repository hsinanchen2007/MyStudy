### 解题思路
官方解复制

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function longestConsecutive($nums) {
        $max_len = 0;

        $map = [];//把原数组转化为哈希字典，便于之后排查
        //O(n)
        foreach($nums as $num){
    		$map[$num] = 1;
    	}

        //O(n)
        foreach($nums as $num){
            //没有比当前数字还要小一的数字
            //也就是说当前数字是可能连续序列的最小值
            if(!isset($map[$num-1])){
                $cur_num = $num;
                $cur_len = 1;

                //以此数字为基准，依次升幂检查是否存在
                while(isset($map[$cur_num+1])){
                    $cur_num++;
                    $cur_len++;
                }

                //更新最长序列长度
                $max_len = max($max_len,$cur_len);
            }
        }

        return $max_len;

    }
}
```