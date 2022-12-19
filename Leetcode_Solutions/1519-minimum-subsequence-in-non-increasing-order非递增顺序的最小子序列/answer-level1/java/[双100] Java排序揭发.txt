
### 解题思路
一开始想的是动态规划,后来想着想着发现直接排序就能搞定。
1.默认从小到大排序
2.从后往前逐个尝试将对于的数字计算到sum,就能得到数量最少、值最大的符合要求的序列。
### 代码

```java
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int sum =0;
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i=nums.length-1;i>=0;i--){
          ans.add(nums[i]);
          sum += nums[i];
          int otherSum = 0;
          for (int j=i-1;j>=0;j--) {
              otherSum+=nums[j];
              if (sum < otherSum) {
                  break;
              }
          }
          if (sum>otherSum) {
              break;
          }
        }
        return ans;
    }
}
```