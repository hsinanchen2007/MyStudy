### 解题思路
此处撰写解题思路
两次2分一次过，JAVA : 0 ms 
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :42.3 MB, 在所有 Java 提交中击败了71.09%的用户

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
            int[] a={-1,-1};
        int low=0,high=nums.length-1;
        int mid=(high+low)>>1;
        while (low <= high) {
            mid=(high+low)>>1;
            if (nums[mid] == target) {
                if(mid==0 || nums[mid-1]!=target) {
                    a[0]=mid;
                    break;
                }
                else high=mid-1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        low=0;high=nums.length-1;
        while (low <= high) {
            mid=(high+low)>>1;
            if (nums[mid] == target) {
                if(mid==nums.length-1 || nums[mid+1]!=target) {
                    a[1]=mid;
                    break;
                }
                else low=mid+1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }

        return a;
    }
}
```