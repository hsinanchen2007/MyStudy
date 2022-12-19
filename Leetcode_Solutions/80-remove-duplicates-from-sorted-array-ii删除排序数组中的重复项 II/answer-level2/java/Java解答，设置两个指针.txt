
### 解题思路
![批注 2019-12-07 164702.png](https://pic.leetcode-cn.com/05d04341f143cd65540a4b4261fd1964f66826152eb066a3181773108ba20dc2-%E6%89%B9%E6%B3%A8%202019-12-07%20164702.png)
设置两个指针pre和cur。
如果第一次pre和cur相同就两者都移动，如果第大于一次两者相同就保持pre不动，只移动cur。
直到pre和cur的值不同。这时把cur的值覆盖在pre+1上。

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int pre=0, cur=1;
        int cnt=1;
        while (cur<nums.length) {
            if((nums[pre]==nums[cur])&&(cnt==0)) {
                cur++;
            }
            else if ((nums[pre]==nums[cur])&&(cnt!=0)) {
                nums[pre+1] = nums[cur];
                cnt--;
                pre++;
                cur++;
            }
            else if (nums[pre]!=nums[cur]) {
                nums[pre+1] = nums[cur];
                pre++;
                cur++;
                cnt = 1;
            }
        }
        return ++pre;
    }
}
```