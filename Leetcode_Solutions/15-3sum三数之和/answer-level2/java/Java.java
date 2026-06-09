### 解题思路
指针用作除i之外另外两个数遍历的循环，难点主要在去重上。这里的思想是，先排序。然后因为排序后的相邻的数字都可能是会重复的解。因此只用第一个重复的数用来计算，直接跳过其他所有重复的数。

### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList();
        int length = nums.length;
        if(length <=2){
            return result;
        }
        Arrays.sort(nums);
        for(int i =0;i<length-2;i++){
            if(i == 0||(i>0 && nums[i]!=nums[i-1])){//跳过可能重复的答案
                int left = i+1;
                int right = length -1;
                while(left<right){
                    int sum = nums[i]+nums[left]+nums[right];
                    if(sum==0){
                        List<Integer> temp = new ArrayList();
                        temp = Arrays.asList(nums[i],nums[left],nums[right]);
                        // temp.add(sums[left]);
                        // temp.add(sums[right]);
                        result.add(temp);
                        while(left<right && nums[left]==nums[left+1]){left++;}
                        while(left<right && nums[right]==nums[right-1]){right--;}
                        left++;//跳过重复值，因为此时已经使用过该重复值的第一个了，所以循环中跳到最后一个重复值，出来还得在跳一次才能跳过重复值。
                        right--;
                    }else if(sum<0){
                        // while(left<right && nums[left]==nums[left+1]){left++;}
                        left++;
                    }else{
                        // while(left<right && nums[right]==nums[right-1]){right--;}
                        right--;
                    }
                }
            }
        }
        return result;
    }
}
```