我的思路是这样的，所谓要把0移动到数组后面，其实就是把非0数给移动到数组前面，而每个非0数需要移动的步数其实就是这个非0数前面0的个数。

例如题目中的case：

```
[0, 1, 0, 3, 2]
```

按我的思路，那就是1需要移动1步，3和2需要移动两步。在完成这三个数的移动后，将后面补0即可。

这里其实就是维护了一个计数变量count，请看代码，然后画个图就能懂了。

```java
class Solution {
    public void moveZeroes(int[] nums) {
        int count = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == 0) {
                count++;
            }else {
                nums[i - count] = nums[i];
            }
        }
        for(int i = nums.length - count; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
}
```
