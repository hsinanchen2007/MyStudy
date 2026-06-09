### 解题思路
暴力法：直接穷举1到target/2+1的所有连续序列的和
因为要找的是连续序列，所以至少要是两个连续的数，所以如果找到大于target的一半时还没找到，那么任意两个连续的数之和都大于target了
时间复杂度：O(n*n)

双指针：定义两个变量，每次循环求low到high的和；在循环里面把大于、小于、等于的三种不同情况列出来就可以了
  如果等于target，就记录当前的序列，并且将序列继续向前推进，即增大low，sum-low；
  如果大于target，sum-low，同时low++；
  如果小于target，sum+high，同时high++；
时间复杂度：O(n*logn)

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        ArrayList<int[]> list=new ArrayList<>();
        int low=1;
        int high=1;
        int sum=0;
        while(low<target/2+1){
            if(sum<target){
                sum+=high;
                high++;
            }else if(sum>target){
                sum-=low;
                low++;
            }else{
                int[] num=new int[high-low];
                for(int i=low;i<high;i++){
                    num[i-low]=i;
                }
                list.add(num);
                sum-=low;
                low++;
            }
        }
        return list.toArray(new int[list.size()][]);
    }
}
```