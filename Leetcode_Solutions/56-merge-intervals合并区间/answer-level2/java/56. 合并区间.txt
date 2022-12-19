### 解题思路
一开始没有排序，一直过不了；
看了题解以后借用了大佬的排序思想...
```
        Arrays.sort(intervals,new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[0]-b[0];
            }
        });
```



### 代码

```java
import java.util.*;
import java.util.Arrays;
class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals == null){
            return null;
        }
        int num = intervals.length;
        int[][] r = new int[0][];
        if(num == 0){
            return r;
        }
        if(num == 1){
            return intervals;
        }

        Arrays.sort(intervals,new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[0]-b[0];
            }
        });

        Stack<Integer> res = new Stack<Integer>();
        res.push(intervals[0][0]);
        res.push(intervals[0][1]);
        for(int i = 0;i<num-1;i++){
            int j= i+1;
            //res.push(intervals[i][0]);
            //res.push(intervals[i][1]);
            if(res.peek()>=intervals[j][0]){
                if(res.peek()>=intervals[j][1]){
                    continue;
                }else{
                    res.pop();
                    res.push(intervals[j][1]);
                }

            }else{
                res.push(intervals[j][0]);
                res.push(intervals[j][1]);
            }
        }
        int row = res.size()/2;
        int[][] ans = new int[row][2];
        int i= row-1;
        while(!res.isEmpty()){
            ans[i][1]=res.pop();
            ans[i][0]=res.pop();
            i--;
        }
        return ans;
    }
}
```