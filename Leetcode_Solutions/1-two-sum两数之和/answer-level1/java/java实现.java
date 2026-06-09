### 解题思路
此问题主要通过两个for循环来实现，个人感觉代码执行效率较低。

### 代码

```java
public class Solution  {
    public static  void main (String [] args){
        int [] nums = {2, 7, 11, 15};
        int target = 9;
        Solution t = new Solution();
        t.twoSum(nums,target);
        for (int i=0;i<t.twoSum(nums,target).length;i++) {
            System.out.print(t.twoSum(nums,target)[i]);
        }
    
    }

    public int[] twoSum (int [] nums,int target) {
        int result [] = new int[2];
        for (int i=0;i<nums.length;i++) {

            for (int j=0;j<i+1;j++) {
                if (i==j) {
                    continue;
                }
                if (nums[i]+nums[j]==target) {
                    result[0] = j;
                    result[1] = i;
                }

            }

        }
        return result;
    }
}

```