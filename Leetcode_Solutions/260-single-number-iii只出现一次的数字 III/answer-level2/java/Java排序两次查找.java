### 解题思路
思路类似 [只出现一次的数字(https://leetcode-cn.com/problems/single-number/) ，先排序

同样分为三种情况：
1. ... 1 1 2 2 ...
2. ... 1 2 ... 2 1 ...
3. 2 ... 2 1 1

分为两步：先寻找第一个，记录下来，然后从找到的这一个元素的下一个元素进行寻找，这里就和 [只出现一次的数字(https://leetcode-cn.com/problems/single-number/) 一样

### 代码

```java
class Solution {
    public int[] singleNumber(int[] nums) {
        int[] result=new int[2];
        int count=0;

        Arrays.sort(nums);
        int len = nums.length;

        if(len==2){
            result[0]=nums[0];
            result[1]=nums[1];

            return result;
        }

        int i=0;
        for(;i<len;i=i+2){
            if(i==len-2){
                result[0]=nums[i];
                result[1]=nums[i+1];

                return result;
            }

            if(nums[i]!=nums[i+1]){
                result[count]=nums[i];
                count++;
                break;
            }
        }

        int j=i+1;
        for(;j<len;j=j+2){
            if(j==len-1){
                result[count]=nums[j];
                break;
            }
            if(nums[j]!=nums[j+1]){
                result[count]=nums[j];
                break;
            }

        }

        return result;
    }
}
```