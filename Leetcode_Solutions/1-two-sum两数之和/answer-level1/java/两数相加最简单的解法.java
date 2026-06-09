### 解题思路
通过for循环来进行解决，两层嵌套，然后进行比较。

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
       int[] m=new int[2];
      for(int i=0;i<nums.length;i++){
          for(int j=0;j<nums.length;j++){
              if(nums[i]+nums[j]==target && j!=i){
                  m[0]=i;
                  m[1]=j;
                  return m;
              }
              }
          }
          return m;
      }
    }

```