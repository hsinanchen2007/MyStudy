### 解题思路



如果不考虑前后相连的情况 出现最大值时有四种情况
① 首选 尾选  ②首选 尾不选
③ 首不选 尾选 ④ 首不选 尾不选

现在要避免出现第一种情况 ，所以只有三种情况。

先看首不选时，这时尾部可以自由选取。转换一下思路，这跟我们把首元素抛出在外，首尾允许同时选中，是一种情况。

当尾不选时，同理首部可以自由选取。转换一下，这跟我们把尾部元素抛出在外，首尾允许同时选中，是一种情况。

然后,比较这两种情况中的较大值。
### 代码

```java
class Solution {

    public int rob(int[] nums) {

        if(nums.length==0){
            return 0;
        }

        if(nums.length==1){
            return nums[0];
        }

        if(nums.length==2){
            return nums[0]>nums[1]?nums[0]:nums[1];
        }

        //这里为了方便调通用方法，不想这样写的话也可以直接遍历nums，控制下遍历条件就行
        int[] nums1 = Arrays.copyOfRange(nums,0,nums.length-1);
        int[] nums2 = Arrays.copyOfRange(nums,1,nums.length);

        return  rob1(nums1)>rob1(nums2)?rob1(nums1):rob1(nums2);
    }



    public int rob1(int[] nums) {
        //对于一个点只有选中和不选中两种可能
        if(nums.length==1){
            return nums[0];
        }

        if(nums.length==2){
            return nums[0]>nums[1]?nums[0]:nums[1];
        }

        int chosenLastMax= nums[1];
        int notChosenLastMax= nums[0];

        for (int i = 2; i < nums.length; i++) {
            int current = nums[i];
            int chosenCurrentMax = notChosenLastMax+current;
            int notChosenCurrentMax =  chosenLastMax>notChosenLastMax?chosenLastMax:notChosenLastMax;

            chosenLastMax = chosenCurrentMax;
            notChosenLastMax = notChosenCurrentMax;
        }

        return chosenLastMax>notChosenLastMax?chosenLastMax:notChosenLastMax;
    }


}
```