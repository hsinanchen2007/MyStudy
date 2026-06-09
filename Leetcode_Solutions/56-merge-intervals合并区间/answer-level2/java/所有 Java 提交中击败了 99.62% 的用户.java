### 解题思路
归并排序的思想, 和会议室 那到题目很像, 具体见注释,  nlog(n)排序，线性扫描一遍的解法.

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {

        if(intervals.length == 0) return new int [0][0]; //针对[]空的输入。

        int start [] = new int [intervals.length];
        int end [] = new int [intervals.length];
        List<int[]> my = new ArrayList<>();  //额外的空间, 非原地排序
        
        for(int i = 0; i<intervals.length;i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        Arrays.sort(start);   //(a,b)区间, a,b分别排序, 有会议室的思想, 只关心起始和结束。
        Arrays.sort(end);
        int num = 0;  //统计最终合并后的区间数目
        int i = 0;
        int j = 0;
        int temp = start[0];

        while(j <= start.length){   //两 有序数组 合并成一个, 归并的思想

            if( i != start.length && start[i] <= end[j]){
                i++;  
            }
            else{
                j++;
            }
            
            if(i != 0 && i == j) {          //独立区间的检测
                my.add(new int[]{temp,end[j-1]});
                num++;
                if(j < start.length) temp = start[i]; //防止i数组越界！！！
            }

        }
        return my.toArray(new int[num][2]);

    }
}
```