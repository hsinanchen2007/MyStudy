### 四数之和其实就是在[三数之和](https://leetcode-cn.com/problems/3sum/solution/hua-jie-suan-fa-15-san-shu-zhi-he-by-guanpengchn/)题目的基础上再多做一层循环嵌套，本质的算法思想是一致，都是采用双指针的解法。

#### 举个例子：

测试用例：`nums：[1, 0, -1, 0, -2, 2]`，`target：0`

先对`nums`做一个升序的排序得到`[-2,-1,0,0,1,2]`

利用两层循环首先是：`i=-2,j=-1`,然后剩下的区间为：`[0,0,1,2]`,利用双指针进行遍历

即有：`i=-2,j=-1,L=0,R=2`,四数相加等于：`-1`,不等于且小于`target`，左指针加一位，即：`L++`

否则右指针减一位：`R--`

若等于`target`，就存储在结果中，并对左右指针相邻重复的数做去重操作，继续上面的步骤 

```C# []
public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        IList<IList<int>> resultList=new List<IList<int>>();
        int Length=nums.Length;
        if(nums==null||Length<4) return resultList;
        Array.Sort(nums);
        for(int i=0;i<Length;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;//去重
            for(int j=i+1;j<Length;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;//去重
                int L=j+1;
                int R=Length-1;
                while(L<R){
                    int sum=nums[i]+nums[j] + nums[L] + nums[R];
                    if(sum==target){
                        resultList.Add(new List<int>{nums[i],nums[j],nums[L],nums[R]});
                        while(L<R&&nums[L]==nums[L+1]) L++;//去重
                        while(L<R&&nums[R]==nums[R-1]) R--;//去重
                        L++;
                        R--;
                    }
                    else if(sum>target) R--;
                    else if(sum<target) L++;
                }
            }
        }
        return resultList;
    }
}
```

