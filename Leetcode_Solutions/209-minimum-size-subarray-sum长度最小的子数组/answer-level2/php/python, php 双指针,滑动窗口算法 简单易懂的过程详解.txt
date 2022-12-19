## 解题思路:
先考虑`极限情况`,数组的全部值求和刚好 ==s 那么我们要找到的最小长度 就是 数组长度,我们用双指针模拟一下找这个 `极限情况`的做法  
## 步骤如下: 
模拟了滑动窗口, 用快慢双指针原理来找到最小长度 
1. 双指针初始都在数组最左侧,0
2. 保持左指针不动,移动右指针,并且对左右指针区间的值求和
3. 判断 区间 和 是否>=s ,小于就继续移动右指针,直到找到一个区间和>=s后(`极限情况`就是右指针到了数组末尾后 区间和 == s ),开始进行区间内的判断,因为右指针指向的值可能会很大,所以需要对左指针的区间进行`瘦身`保证最小长度
4. 右指针停住后,开始移动左侧,并且从区间和里移除掉左指针指向的值,一直移动到和<s后 左指针停住,继续移动右指针.
5. 用min 来 判断每一次区间的数量大小
6. 右指针到头的时候 结束并返回长度  

## 代码如下:
抽空补一下php的

```python []
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        if sum(nums) == s:
            return len(nums)
        if sum(nums) < s:
            return 0
        sum_temp = left = 0
        min_len = len(nums)
        for right in range(len(nums)):
            sum_temp += nums[right]
            while sum_temp >= s:
                min_len = min(min_len, right-left+1)
                sum_temp -= nums[left]
                left += 1       
        return min_len
```

```php []
class Solution {

    /**
     * @param Integer $s
     * @param Integer[] $nums
     * @return Integer
     */
    function minSubArrayLen($s, $nums) {
        $nums_sum = array_sum($nums);
        if($nums_sum == $s){
            return count($nums);
        }
        if($nums_sum < $s){
            return 0;
        }
        $left = 0;
        $length = count($nums);
        $sum_temp = 0;
        foreach($nums as $right => $val){
            $sum_temp += $val;
            while($sum_temp>=$s){
                $length = min($length, $right-$left+1);
                $sum_temp -= $nums[$left];
                $left += 1;
            }   
        }
        return $length;
    }
}
```