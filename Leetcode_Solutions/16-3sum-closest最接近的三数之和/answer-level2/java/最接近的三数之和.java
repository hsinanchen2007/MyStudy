### 解题思路
    与三数之和采用相似的解法，外面一层for循环，里面首尾同时向里收缩，降低时间复杂度。

### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int len=nums.length;
        int rs=10000000;
        int res=0;
        for(int i=0;i<len;i++){
            for(int j=i+1,k=len-1;j<k;){
                int sum=nums[i]+nums[j]+nums[k];
                int tp=sum-target;
                int sub=Math.abs(tp);
                if(sub<rs){
                    rs=sub;
                    res=sum;
                }
                if(tp<0)
                    j++;
                else
                    k--;
            }

        }
        return res;
    }
}
```