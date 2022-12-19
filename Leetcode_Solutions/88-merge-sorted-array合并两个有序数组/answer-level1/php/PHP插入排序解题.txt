![image.png](https://pic.leetcode-cn.com/3bd123e7d239768e3e40d38c918c4be95ffc840b6f2301eb8e3ecddc9728e085-image.png)
将nums2合并到nums1中,使用插入排序解题
```
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer $m
     * @param Integer[] $nums2
     * @param Integer $n
     * @return NULL
     */
    function merge(&$nums1, $m, $nums2, $n) {
        $count = count($nums1);
        for ($i=$m, $times = 0;$i<$count;$i++,$times++) {
            $nums1[$i] = $nums2[$times];
        }

        for ($i=1;$i<$count;$i++) {
            $value = $nums1[$i];
            for ($j=$i-1;$j>=0;$j--) {
                if ($nums1[$j] > $value) {
                    $nums1[$j+1] = $nums1[$j];
                } else {
                    break;
                }
            }
            $nums1[$j+1] = $value;
        }
    }
}
```
