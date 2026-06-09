### 解题思路
1、第一步先对区间进行排序。
   保证左边的元素的第一项一定比右边的元素第一项小

2、排序完成后，我们利用栈来帮助我们做合并。
   // 栈里面的每一个元素都是一个数组，数组里只有两个元素 
   2.1 定义栈为Stack<int[]> stack = new Stack<int[]>();
     
   2.2 循环intervals,并与stack的顶部元素进行比较
        int[] peekArray = stack.peek();
        如果intervals[i][0] <=peekArray[1]  说明两者有交集,那么将peekArray弹出
        获取交集的右边值max = Math.max(intervals[i][1],peekArray[1])
        再将新的区间new int[]{peekArray[0],max}压入栈中
        如果intervals[i][0] > peekArray[1] 说明两者没有交集，则将如果new int[]{intervals[i][0],intervals[i][1]} 压入栈
   
   2.3 最后循环stack，将结果输出
   时间复杂度:假设二维数组的行数为N，那么
   //第一个为排序耗时，第二个为循环操作耗时
   O(T) = O(N*N)+O(N)

   空间复杂度:
   O(N) 我们利用到了一个堆栈来保存中间结果。
  
### 代码

```java
class Solution {

    private void sort(int[][] intervals){
        int rowLength = intervals.length;
        int tmp0 = 0,tmp1 = 0;
        for(int i = 0;i<rowLength;i++){
            for(int j=i+1;j<rowLength;j++){
                if(intervals[i][0]>intervals[j][0]){
                    tmp0 = intervals[i][0];
                    tmp1 = intervals[i][1];
                    intervals[i][0] = intervals[j][0];
                    intervals[i][1] = intervals[j][1];
                    intervals[j][0] = tmp0;
                    intervals[j][1] = tmp1;
                }else if(intervals[i][0] == intervals[j][0]){
                    if(intervals[i][1]>intervals[j][1]){
                        tmp0 = intervals[i][1];
                        intervals[i][1] = intervals[j][1];
                        intervals[j][1] = tmp0;
                    }
                }
            }
        }
    }

    public int[][] merge(int[][] intervals) {
        if(intervals==null||intervals.length<=1){
            return intervals;
        }
        sort(intervals);
        //每个元素都是一个数组，数组有两个值
        Stack<Integer[]> path = new Stack<>();
        for(int i = 0;i<intervals.length;i++){
            if(path.isEmpty()){
                path.push(new Integer[]{Integer.valueOf(intervals[i][0]),Integer.valueOf(intervals[i][1])});
            }else{
                Integer[] peekArray = path.peek();
                if(intervals[i][0]>peekArray[1]){
                    //说明第二项的开始元素比第一项的结尾元素还要大,那么说明两者没有交集
                    path.push(new Integer[]{Integer.valueOf(intervals[i][0]),Integer.valueOf(intervals[i][1])});
                }else{
                    //说明两者有交集,比较第一个元素的最后一项和第二个元素的最后一项
                    int maxValue = Math.max(peekArray[1],intervals[i][1]);
                    Integer[] pop = path.pop();
                    path.push(new Integer[]{pop[0],maxValue});
                }
            }
        }
        int[][] result = new int[path.size()][2];
        for(int i = 0;i<path.size();i++){
            Integer[] integers = path.get(i);
            result[i][0] = integers[0];
            result[i][1] = integers[1];
        }
        return result;
    }
}
```