```
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        //桶排序思想，前缀和
        int[] tmp = new int[101];//声明一个桶
        int i;
        for(i = 0; i < nums.length; i++){//初始化桶，桶中的值为对应下标的数字出现的次数
            tmp[nums[i]] += 1;
        }
        for(i = 1; i < 101; i++){ //计算桶中前缀和
            tmp[i] += tmp[i-1];
        }
        for(i = 0; i < nums.length; i++){//修改tmp存储的值为比其下标对应数字小的数字个数
            tmp[nums[i]]--; 
        }
         for(i = 0; i < nums.length; i++){//将tmp中结果对应存到nums中
             nums[i] = tmp[nums[i]];
        }
        return nums;
    }
}
```
