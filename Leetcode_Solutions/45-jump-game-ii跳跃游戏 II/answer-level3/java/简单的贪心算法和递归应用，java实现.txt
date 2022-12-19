    
执行用时 :2 ms,在所有 Java 提交中击败了99.85%的用户
内存消耗 :43.1 MB,在所有 Java 提交中击败了47.78%的用户
   这道题算是困难难度中非常简单的了，主要就是一个贪心算法而已，然后我编程的时候用到了递归实现这个贪心算法。
   这道题的重点在于一个标准，就是选择下一步位置的贪心标准。也就是下一步之内能够到达最大距离。这个最大距离应该是当前节点与能够到达的某一节点之间的距离加上他对应的nums[]值。比如说{4,3,1,1}，3这个节点的最大距离应该是1+3=4，就是3和开始的4之间距离为1，再加上3，就是选择这个节点后一步之内能够到达的最大距离，这样的话每次把范围内的节点的最大距离都算出来，选择一个最大值一直贪心下去，就得到了最小的步数。就这么简单。代码如下：
```   
 public int jump(int[] nums) {
        if (nums.length==1||nums.length==0)
            return 0;
        int count = jumpToNext(nums,0);
        return count;
    }
    public static int jumpToNext(int[] nums,int start){
        if (nums[start]>=nums.length-start-1){
            return 1;
        }
        int next = jumpWhere(nums,nums[start],start);
        return jumpToNext(nums,next)+1;
    }
    public static int jumpWhere(int[] nums,int max,int location){
        int partMax = nums[location+1]+1;
        int result = location+1;
        for (int i=2;i<=max;i++){
            if (nums[location+i]+i>=partMax) {
                partMax = nums[location + i]+i;
                result = location+i;
            }
        }
        return result;
    }
代码块
```
然后这里的递归是借用二叉树中算高度的那块思想，来计数需要的步数，因为一开始用静态变量在leetcode上跑出来的结果和IDEA不同，所以改用了这种方法。也就是每次加一。看不懂可以问我。大二学生的水平有限，如果有能优化的地方也欢迎大家指出来，我可以再改改。