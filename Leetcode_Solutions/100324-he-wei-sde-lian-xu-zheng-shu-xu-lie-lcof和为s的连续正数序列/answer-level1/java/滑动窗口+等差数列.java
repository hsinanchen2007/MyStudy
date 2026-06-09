### 解题思路
滑动窗口+等差数列;
首先如果target小于3时候没有任何结果满足条件所以target必须大于等于3,而且数组的最大值不可能超过target/2或target/2+1,因为一旦超过这个边界,和一定大于target
定义两个指针分别是left=1,与right=2,窗口的边界
利用等差数列求和用sum代表与target进行比较
如果sum==target说明从left到right之间的数满足条件,然后left++,right++,如果相同边界,不可能存在两组数组,所以直接改变从窗口左右边界
如果sum<target说明窗口中的和不足,加大右窗口right++;
如果sum>target说明窗口中的和太大,缩小左窗口left++;

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        if(target<3){
            return new int[0][];
        }
        //存放结果
        List<int []> result=new ArrayList<>();
        //计算最大边界
        int len=target%2==0?target/2:target/2+1;
        int left=1,right=2;
        while(left<right&&right<=len){
            //等差数列计算
            int sum=(left+right)*(right-left+1)/2;
            //满足条件
            if(sum==target){
               int []nums=new int[right-left+1];
               int temp=left;
                //记录结果
               for(int i=0;i<nums.length;i++){
                   nums[i]=temp++;
               } 
               left++;
               right++;
               result.add(nums);
            }else if(sum>target){
                //左窗口移动
                left++;
            }else{
                //右窗口移动
                right++;
            }
        }
        return result.toArray(new int[0][]);
    }
}
```