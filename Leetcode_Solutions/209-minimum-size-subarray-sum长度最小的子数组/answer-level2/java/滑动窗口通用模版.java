### 解题思路
看到这类题型，首先想到“滑动窗口算法(Sliding window algorithm)”,不了解“滑动窗口算法”可以自行搜索一下。
"滑动窗口算法"的要素 
1. 肯定要设计左右边界: left , right；
2. 满足窗口的条件(此处为窗口值的和windowSum）；
3. 最值变量ans;
4. 至少一次循环遍历过程；
5. 至少一次比较大小的过程；
6. 找出窗口滑动的所需逻辑即可；

### 代码

```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int left = 0 ;
        int right =0 ;
        int windowSum = 0;
        int ans = Integer.MAX_VALUE;
        while(right < nums.length){
            if(windowSum+nums[right] < s){
                windowSum += nums[right];
                right ++;
            }else{
                if(ans > right-left+1){
                    ans = right-left+1;
                }
                windowSum -= nums[left];
                left++;
            }
        }
        return ans == Integer.MAX_VALUE? 0 : ans;
    }
}
```