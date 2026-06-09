执行用时 :8 ms, 在所有 Java 提交中击败了92.80% 的用户
内存消耗 :50 MB, 在所有 Java 提交中击败了62.79%的用户


思路是这样的：比如我nums[3]+nums[4]+nums[5]能够被K整除，也就是前五项的和减去前两项的和能够被K整除，也就是说前五项的和对K取模跟前两项的和对K取模的结果是一样的，根据这个思路我想到一个解题方法  代码如下

```
    int result=0;int sum=0;//分别记录结果数目和前面数字之和
        int []nums=new int[K];
        for (int i = 0; i <A.length; i++) {
            sum+=A[i];             求前N项和
            nums[((sum%K)+K)%K]++;//加上K再取一次模  消除负数；
        }
        for (int i = 0; i <K; i++) {
            if (nums[i]>1){
                result+=(nums[i])*(nums[i]-1)/2;//任意两个模相同的位置之间的子数组符合要求
            }
        }
        result+=nums[0];//模为0的自己一个人就ok  所以额外加一次
        return result;
```
