### 解题思路
执行时间：1ms
内存消耗：39MB
时间复杂度：O(n)
思路见代码注释
### 代码

```java
public class Solution {
    private static boolean canJump(int[] nums) {
        boolean flag = false;
        //特例,数组长度是1，自然成立
        if (nums.length==1) return true;
        //第二个参数是代表要到达的位置，初始值是数组的最后一个元素的秩
        flag = recursion(nums,nums.length-1);
        return flag;
    }

    private static boolean recursion(int[] nums, int target){
        //递归基，如果需要到达的数组的位置是第一个元素的话，自然成立
        if (target==0) return true;

        //递归体
        //初始步长是1，设需要到达的位置是a，则我们从a的前面一个元素开始向前循环，步长最开始是1
        int step = 1;
        for (int i = target-1;i>=0;i--){
            //如果这个数组元素的值大于等于到达指定位置的所需要的步长，则只要能先到达这个元素的位置，则就一定可以到达指定位置
            //故递归，传入第2个参数是该数组元素的秩
            if (nums[i]>=step) return recursion(nums,i);
            //如果小于，则该元素到不了指定位置，步长+1，测试再前一个数组元素
            step += 1;
        }
        //如果数组中没有元素能到达指定位置的元素，则自然返回false
        return false;
    }


    public static void main(String[] args) {
        int[] nums = {3,2,1,0,4};
        int[] nums2 = {2,3,1,1,4};
        int[] nums3 = {2,0,0};
        System.out.println(canJump(nums3));
    }
}
```