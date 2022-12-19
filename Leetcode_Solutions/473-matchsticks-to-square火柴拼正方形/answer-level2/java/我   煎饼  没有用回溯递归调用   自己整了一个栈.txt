执行用时 :2 ms, 在所有 Java 提交中击败了99.65% 的用户
内存消耗 :34.4 MB, 在所有 Java 提交中击败了90.91%的用户

思路就不写了。代码如下   有问题可以给我留言或者评论
```
class Solution {
    public boolean makesquare(int[] nums) {
        int len = nums.length; int total=0;
        for (int i = 0; i <len; i++)total+=nums[i];
        if (len<4||total%4!=0)return false;//火柴数目小于4或者火柴总长度不能被4整除
        int n=total/4; int i=0;//老规矩  定义在外面好判断进行到哪了
        Stack<Integer> stack=new Stack<>();//用来存放已取得值
        for ( i= 0; i <4; i++) {//总共进行四次
            Arrays.sort(nums);//排序
            int sum=nums[len-1];//累积和
            if (sum==n){//一开始就相等
                nums[len-1]=0;
                continue;
            }
            int index=len-2;//表示下一个要进栈的索引
            int []nums2=new int[len]; nums2[0]=nums2[0];
            for (int j = 1; j <len; j++) {//这个nums2真的是灵魂所在
                nums2[j]=nums2[j-1]+nums[j];
            }
            while (index>=0){
                if (sum+nums[index]==n){//找到能够凑成一条边的数
                    stack.push(index);
                    break;
                }
                else if (sum+nums[index]>n){//分几种情况  
                    if (index>0)index--;// 后面还有数的话下一个数进来
                    else if (index==0){
                        if (!stack.isEmpty()){
                            index=stack.pop()-1;
                            sum-=nums[index+1];
                        }
                        else return false;    //第一个数加最后一个数都太大了
                    }
                }
                else {
                    if (sum+nums2[index]<n){//加上后面所有的数还是小了
                        if (!stack.isEmpty()){//栈里面有数   出栈
                            index=stack.pop()-1;
                            sum-=nums[index+1];
                        }
                        else return false;    //栈里面没有可以出的数了
                    }
                    else {//继续往后加
                        sum+=nums[index];
                        stack.push(index--);
                    }
                }
            }
            while (!stack.isEmpty()){//把已经用过的数置零
                nums[stack.pop()]=0;
            }
            nums[len-1]=0;
        }
        return true;//恭喜坚持到了最后  
    }
}
```
