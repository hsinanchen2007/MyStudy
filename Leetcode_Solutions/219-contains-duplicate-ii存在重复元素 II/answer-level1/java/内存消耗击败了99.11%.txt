### 解题思路
最土的办法，设置两个for循环逐一比较。不过要注意临界情况（i+k和num.length的大小）

### 代码

```java
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int length=nums.length;
        if((nums.length==0)||(nums.length==0)) {
            return false;
        }

        for (int i=0; i<length-1; i++) {
            if(i+k>length-1) {
                for (int j=i+1; j<=length-1;j++) {
                    if(nums[i]==nums[j]) return true;
                }
            }
            else {
            for (int j=i+1; j<=i+k;j++) {
                if(nums[i]==nums[j]) return true;
            }
            }
        }

        return false;
    }
}
```