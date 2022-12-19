### 解题思路
各位大佬们，我总感觉我写的代码很蠢，希望各位大佬能对我写的代码提出改进意见，万分感谢
执行用时 :1 ms, 在所有 Java 提交中击败了99.96%的用户
内存消耗 :36.9 MB, 在所有 Java 提交中击败了99.36%的用户

## 代码

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        //双指针法
        //定义一个快指针，一个慢指针和一个匹配次数计数器
        int slowPoint = 0;
        boolean matchTwice = false;
        //快指针遍历数组，如果快指针所在元素等于慢指针，则慢指针当前下标及下一个下标都等于快指针当前元素，匹配计数器变为true。
        for(int fastPoint = 1;fastPoint<nums.length;fastPoint++){
            if(nums[fastPoint]==nums[slowPoint]&&matchTwice==false){
                nums[slowPoint]=nums[fastPoint];
                nums[slowPoint+1]=nums[slowPoint];
                slowPoint++;
                matchTwice=true;
            
            }
            if(nums[fastPoint]!=nums[slowPoint])
            {
                //如果快指针不等于慢指针则慢指针推进下标，计数器归零
                slowPoint++;
                nums[slowPoint]=nums[fastPoint];
                matchTwice=false;
            }
        }
        return slowPoint+1;
    }
}
```