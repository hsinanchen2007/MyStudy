### [剑指Offer03. 数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)
#### 题目描述
![image.png](https://pic.leetcode-cn.com/9fa02139261628a00329c22967d6f8bedd5e3a7b254b6c54aa14d672c67485a6-image.png)
#### 思路
- 把数组想象成一排**座位**，数组下标表示**座位号**，数组中的元素值想象成**小朋友的名字**（根据题意，会有重名），一开始小朋友们随意坐在椅子上。
- 我们的目标是让小朋友i要坐在i号椅子上（如：元素3要坐在`num[3]`上）
- 遍历数组只要`i`号椅子上坐的不是`i`（`if(num[i] != i)`），那么去看看i号椅子上坐的是谁
    - 如果i号椅子上坐的也是i（即出现同名情况），跳出循环即可
    - 如果i号椅子上坐的不是i，那么将i与i号椅子上的元素交换（`exch()`）

#### 代码
```Java
public int findRepeatNumber(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            while(nums[i] != i){
                if (nums[i] == nums[nums[i]]){
                    result =  nums[i];
                    break;
                }
                exch(nums,i,nums[i]);
            }
        }
        return result;
    }

    private void exch(int[] nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
```