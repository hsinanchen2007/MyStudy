### 解题思路
此处撰写解题思路
本着方便理解的角度整的，首先需要根据start排序，第二步直接合并就行
### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length==0){
            return new int[0][] ;
        }
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0]==o2[0]) return o1[1]-o2[1];
                return o1[0]-o2[0];
            }
        });
        List<int[]>res=new ArrayList<>();
        int []temp=intervals[0];
        for(int i=1;i<intervals.length;i++){
            int ary[]=intervals[i];
            if(temp[1]>=ary[0]){
                temp[0]=Math.min(temp[0],ary[0]);
                temp[1]=Math.max(temp[1],ary[1]);
            }else{
                res.add(temp);
                temp=ary;
            }
        }
        res.add(temp);
        return res.toArray(new int[0][]);
    }
}
```