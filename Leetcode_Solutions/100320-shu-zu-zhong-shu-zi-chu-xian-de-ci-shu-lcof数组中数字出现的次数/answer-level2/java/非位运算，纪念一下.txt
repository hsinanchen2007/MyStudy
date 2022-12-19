### 解题思路
利用数组本身的特性，空间复杂度达标，时间复杂度也达标但是不大好
![image.png](https://pic.leetcode-cn.com/86e7cb57755624ab9adc88a3a7d20a8f802f34ab98a9b901e0080b6dc71575dc-image.png)

### 代码

```java
class Solution {
    public int[] singleNumbers(int[] nums) {

        Arrays.sort(nums);
        int[] res = new int[2];

        int count = 0;
        int i=0;
    
        while((count!=2)){

            if(i==nums.length-1){
                count++;
                res[count-1] = nums[i];
                return res;
            }

            if(nums[i]!=nums[i+1]){
                count++;
                res[count-1] = nums[i];
                i++;
            }else{
                i+=2;
            }
        }

        return res;
    }
}
```