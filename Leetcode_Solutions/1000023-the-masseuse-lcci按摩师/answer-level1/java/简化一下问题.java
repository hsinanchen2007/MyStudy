### 解题思路

每个节点只有两种情况，要么选中，要么没选中，即是求选中当前的最大值，和未选中当前的最大值
选中当前的最大值，受左侧相邻节点响应，选中当前最大值，左侧相邻节点必未被选中，即为未选中左侧相邻节点的最大值
未选中当前的最大值，有两种情况，左侧节点可选中，也可以未被选中，即比较左侧节点选和未被选中当中较大一个

### 代码

```java
class Solution {

    public int massage(int[] nums) {
       
        if(nums.length==0){
            return 0;
        }
        if(nums.length==1){
            return nums[0];
        }
        //每个节点只有一种情况，要么选中，要么没选中，即是求选中当前的最大值，和未选中当前的最大值
        //选中当前的最大值，受左侧相邻节点响应，选中当前最大值，左侧相邻节点必未被选中，即为未选中左侧相邻节点的最大值
        //未选中当前的最大值，有两种情况，左侧节点可选中，也可以未被选中，即比较左侧节点选和未被选中当中较大一个
        int a0 = nums[0];
        int a1 = nums[1];
        int chosenLastMax = a1;
        int notChosenLastMax = a0;

        for (int i = 2; i < nums.length; i++) {
            int current = nums[i];
            //不选中当前最大值
            int temp = chosenLastMax;
            System.out.println("notChosenCurrentMax----->"+(temp>notChosenLastMax?temp:notChosenLastMax));
            //选中当前最大值
            System.out.println("ChosenCurrentMax----->"+(notChosenLastMax+current));

            chosenLastMax = notChosenLastMax+current;
            notChosenLastMax = (temp>notChosenLastMax?temp:notChosenLastMax);
        }

        return notChosenLastMax>chosenLastMax?notChosenLastMax:chosenLastMax;

    }

    


}
```