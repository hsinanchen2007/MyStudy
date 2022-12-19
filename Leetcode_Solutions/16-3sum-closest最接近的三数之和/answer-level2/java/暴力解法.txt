### 解题思路
此处撰写解题思路
很黄很暴力不好，我去看看双指针怎么解
循环遍历，一一对比，就完了
### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int sum = Math.abs(nums[0]+nums[1]+nums[2]-target);
        int p = 0 ;
        int n = nums.length;
          for(int i = 0;i<n-2;i++){
              for(int j = i+1;j<n-1;j++){
                  for(int z = j+1;z<n;z++){
                       int num = nums[i]+nums[j]+nums[z];
                       int  k = Math.abs(num - target);
                        if(sum>=k){
                          sum = k;
                          p = num;
                         }
                  }
              }
          }
          return p;
    }
}
```