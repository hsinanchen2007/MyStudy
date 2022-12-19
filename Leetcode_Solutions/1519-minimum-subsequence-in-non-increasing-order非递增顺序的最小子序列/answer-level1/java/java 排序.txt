题目要求：子序列长度最短，且子序列和大于剩余子序列和

其实题目给了巨大的暗示“非递增顺序”，意味着要给数组排个序，排完序后倒序遍历数组，逐个相加直到和大于sum的1/2即可。

```java
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        
        int tempSum = 0;
        int sum = Arrays.stream(nums).sum();
        Arrays.sort(nums);
        List<Integer> distList = new ArrayList<>();

        for(int i=nums.length -1; i>=0; i--) {
             if(tempSum > sum / 2) {
                break;
            }

            tempSum += nums[i];
            distList.add(nums[i]);
        }

        return distList;
    }
}
```
