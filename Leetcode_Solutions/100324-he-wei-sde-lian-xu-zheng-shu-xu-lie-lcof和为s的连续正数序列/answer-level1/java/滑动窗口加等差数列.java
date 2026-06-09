### 解题思路
1:使用滑动窗口,定义两个指针l=1,r=2,从l到r之间的数的和记为sum
2:当sum大于target时候l++,窗口缩小,使得sum缩小
3:当sum小于target时候窗口r++,窗口增大,使得sum增大
4:当sum等于target时候记录从l到r的所有元素,之后窗口移动l++,r++(因为只可能满足一次,所有同时相加),重复上述操作
5:计算sum的值使用等差数列,首项(l+r)*(r-l+1)/2(等差数列公式,(首项加末项)✖️项数➗2)

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> result=new ArrayList<>();
        //r一定不会超过target的一半(奇数是target/2+1),如果超过了,和一定大于target
        int len=target%2==0?target/2:target/2+1;
        int l=1,r=2;
        while(l<r&&r<=len){
            //等差数列公式
            int sum=(l+r)*(r-l+1)/2;
            if(target==sum){
                int[]nums=new int[r-l+1];
                int tmep=l;
                //记录元素
                for(int i=0;i<nums.length;i++){
                    nums[i]=tmep++;
                }
                result.add(nums);
                //变化窗口
                l++;
                r++;
            }else if(target>sum){
                //窗口增大
                r++;
            }else{
                //窗口缩小    
                l++;
            }
        }
        return result.toArray(new int[0][]);
    }
}
```