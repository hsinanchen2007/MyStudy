### 解题思路
第一种思路：暴力法
直接两层for循环，依次遍历数组nums，判断所有的可能，找到就跳出循环
时间复杂度：O(n*n);
结果：超出时间限制
第二种思路：双指针
其实题中有一个条件我们没有用到，就是数组nums是递增数组，所以就可以从数组的两头开始遍历判断；
定义int low=0,int high=nums.length；对nums[low]+nums[high]和target的值进行比较；
  相等直接赋值，跳出循环；
  nums[low]+nums[high]小，增加low的值，high值不变；
  nums[low]+nums[high]大，减小high的值，low不变;
时间复杂度：O(n)

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result=new int[2];
        int low=0;
        int high=nums.length-1;
        while(low<high){
            int sum=nums[low]+nums[high];
            if(sum==target){
                result[0]=nums[low];
                result[1]=nums[high];
                break;
            }else if(sum<target){
                low++;
            }else if(sum>target){
                high--;
            }
        }
        return result;
    }
}
```