### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findMinArrowShots(int[][] points) {
        int len=points.length;
        if(len==0){
            return 0;
        }
        Arrays.sort(points,new Comparator<int[]>(){//对于区间问题的处理，一般来说                                           //第一步都是排序，相当于预处理降低后续操作难度。
            public int compare(int[] a,int[] b){// 按 end 升序排序
                return a[1]-b[1];
            }
        });
        
        int res=1;// 至少有一个区间不相交
        int xEnd=points[0][1]; // 排序后，第一个区间就是 x
        for(int[] point:points){
            if(point[0]>xEnd){// 找到下一个选择的区间了
                res++;
                xEnd=point[1];
            }
        }
        return res;
    }
}
```