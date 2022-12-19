```
//分治法，时间复杂度o(n)，优点是可以并行运算。
class Solution {
    public int maxSubArray(int[] nums) {
        return mergeCount(nums,0,nums.length)[2];
    }
    /**
     * @return 片段处理后的数组，依次为：左通最大值，右通最大值，局部最大值，总和
     * */
    public int[] mergeCount(int[] nums,int fromIndex,int toIndex){
        int[] result=new int[4];
        if(toIndex-fromIndex!=1){
            int midIndex=(toIndex+fromIndex)>>>1;
            int[] resL=mergeCount(nums,fromIndex,midIndex);
            int[] resR=mergeCount(nums,midIndex,toIndex);
            result[0]=Math.max(resL[0],resL[3]+resR[0]);
            result[1]=Math.max(resR[1],resL[1]+resR[3]);
            result[2]=Math.max(Math.max(resL[2],resR[2]),resL[1]+resR[0]);
            result[3]=resL[3]+resR[3];
            return result;
        }
        Arrays.fill(result,nums[fromIndex]);
        return result;
    }
}

//动态规划,时间复杂度o(n)。(单线程最优解)
class Solution {
    public int maxSubArray(int[] nums) {
        int sum=0,max=Integer.MIN_VALUE;
        for (int num:nums) {
            sum = Math.max(0, sum);
            sum+=num;
            max=Math.max(max,sum);
        }
        return max;
    }
}
```
-------------------------------------------------------------------

### 分治法主要是考虑两个子序列合并后能不能计算出新的子序列的相应值。
分析：
一个片段的最大子序列，在左右两个子片段中要么过界，要么不过界。
如果过界，那么最大子序列必然是“左子序列连通其右边界的最大值”加上“右子序列连通其左边界的最大值”（以下简称左(右)通最大值)）。
如果不过界，那么最大子序列必然是左右两个子序列的最大子序列的较大那个。
无论过不过界，最大子序列必然是这三个值里面最大那个。

继续分析：
现在我们需要求出“左通最大值”跟“右通最大值”，优先考虑这两个值能不能通过其左右子序列的一些值计算出来！

同样是考虑这两个值过不过界的情况，取左通最大值为例：
如果不过界，左通最大值必然等于左子序列的左通最大值。
如果过界，左通最大值必然等于左子序列的总和加上右子序列的左通最大值。
无论过不过界，左通最大值必然是这两个值之中较大那个。

继续分析：
现在我们需要知道片段所有值的总和，这个很简单，就是左右两个子序列的和。

总结一下，对于一个片段，我们要想直接通过其子片段计算出最大子序和，总共需要知道两个子片段的四个值：左通最大值，右通最大值，最大子序和，总和。由于递归是多层的，所以合并之后的片段依然需要求出这四个值。



