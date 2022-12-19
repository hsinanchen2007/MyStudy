### 解题思路
java如何实现函数解耦？

我们不光要求奇数位于偶数前面
还要求负数位于非负数前面
还要求能被3整除的位于不能被3正常的前面
所以将函数进行解耦，分成两个部分，一个用于实现，一个用于判断，当需求改变时，我们只需修改判断函数即可
而java8新增特性lambda表达式可以帮助我们实现此功能
### 代码

```java

class Solution {
    public int[] exchange(int[] nums) {
        return mainPart(nums, isOdd);    //只需修改此处的函数即可实现        
    }

    public int[] mainPart(int[] nums, JudgeFunction judgeFunction){
        int left = 0;
        int right = nums.length-1;

        while(left < right){
            while(left< right && judgeFunction.judge(nums[left]))   left++;            
            while(left < right && (!judgeFunction.judge(nums[right])))  right--;            
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
        }
        return nums;
    }

    interface JudgeFunction {
        boolean judge(int num);
    }

    JudgeFunction isOdd = (int num) -> (num%2)!=0;   //判断奇偶性  //要求奇数位于偶数前面
    JudgeFunction isNegative = (int num) -> (num < 0);   //负数位于非负数前面
    JudgeFunction isThreeTimes = (int num) -> (num%3 == 0);   //能被3整除的位于不能被3正常的前面
    
}
```