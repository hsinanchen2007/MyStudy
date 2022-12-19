### 解题思路
 * two pointer
    * i前面都是奇数
    * i~j 都是偶数
    * j后面未知
    * 当j遇到奇数，每次交换i+1和j位置

### 代码

```java
class Solution {
    public int[] exchange(int[] nums) {
        int i=-1,j=0,n=nums.length;
        while (j<n) {
            if ((nums[j]&1)==1) {
                swap(++i, j++, nums);
            } else {
                j++;
            }
        }
        return nums;
    }
    void swap(int i, int j, int[] nums) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
```
![image.png](https://pic.leetcode-cn.com/e6a4227665a85d986ae57cb4fdd932aea404a3ab334109e5169b472996f3c44d-image.png)
