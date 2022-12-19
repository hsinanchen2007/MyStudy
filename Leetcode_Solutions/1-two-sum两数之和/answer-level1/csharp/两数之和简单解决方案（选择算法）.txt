思想：
    利用选择排序的思想，先确定一个数。然后用这个数和后面所有的数都加一遍，和目标数对比。以此类推，外循环的没一个数和内循环的每一个数相加然后对比是否等于目标数。等于的话就把符合结果的数组下标存到二维数组里！
区别：
两数之和与排序的区别，就是把两个元素对比大小改成了第一个元素加第二个元素等于目标数！
 代码：
```
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        //定义一个结果数组
        int [] Relust=new int[2];
        for(int i=0;i<nums.Length;i++)//第一个元素
        {
            for(int j=i+1;j<nums.Length;j++)//第二个元素
            {
                //判断第一个元素加第二个元素是否等于目标数
                if(nums[i]+nums[j]==target)
                {
                    Relust[0]=i;
                    Relust[1]=j;
                    return Relust;
                }
            }//end for
        }//end for
        return null;
    }
}
```

总结：
这仅仅只是出来结果，但是不是最优解！