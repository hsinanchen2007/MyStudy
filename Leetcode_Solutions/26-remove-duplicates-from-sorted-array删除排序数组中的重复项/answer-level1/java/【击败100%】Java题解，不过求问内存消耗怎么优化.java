![批注 2019-12-07 145745.png](https://pic.leetcode-cn.com/c47ad5dca98b83d4a6320187c14bdd8cf404a54ef9fbdc790ca4d6cb4783bdbf-%E6%89%B9%E6%B3%A8%202019-12-07%20145745.png)


### 解题思路
设置一个指针i和一个计数器cnt。比较num[i]和num[i+1]的值，如果不同，则cnt++, 而且将num[cnt]的值设置为新发现的值

### 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int cnt = 1;
        for (int i=0; i<nums.length-1; i++) {
            if(nums[i]!=nums[i+1]) {
                nums[cnt] = nums[i+1];
                cnt++;
            }
        }
        return cnt;
    }
}
```