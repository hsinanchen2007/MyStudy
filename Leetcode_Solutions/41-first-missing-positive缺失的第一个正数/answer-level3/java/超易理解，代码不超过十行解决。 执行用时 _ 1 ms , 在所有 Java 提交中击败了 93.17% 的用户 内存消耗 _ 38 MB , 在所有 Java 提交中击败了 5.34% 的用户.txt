# 不理解这个为什么是困难的题....感觉挺简单的。本题解是Java版本的，不过解题思路很简单：
**解题思路如下**：
先将最小的正整数ans=1。
在这里为了提高效率，可以先将给定的int数组进行排序(可选)
然后一个for循环遍历数组，如果在数组当中出现了与ans相等的数，则令ans++；
如果在遍历的过程中遍历到的数已经大于ans的时候，表示当前数组后边的数全部都是大于ans的，也就不会再出现与ans相等的数了，此时结束循环即可。最后返回ans。代码如下：

```
class Solution {
   public int firstMissingPositive(int[] nums) {
        int ans=1;
        Arrays.sort(nums);
        for (int i = 0; i <nums.length ; i++) {
            if (nums[i]==ans){
                ans++;
            }
            if(nums[i]>ans) break;
        }
        return ans;
    }
}
```


