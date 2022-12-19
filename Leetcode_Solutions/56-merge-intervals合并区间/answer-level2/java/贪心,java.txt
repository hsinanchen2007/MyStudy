### 解题思路
此处撰写解题思路
整的是比较无脑的贪心算法，先排序，后比较大小
### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(x->x[0]));
        List<int[]> temp=new ArrayList<>();
        if(intervals.length==0)
            return intervals;
        temp.add(new int[]{intervals[0][0],intervals[0][1]});
        for (int i=1;i<intervals.length;i++)
        {
            int[] pre_couple=temp.get(temp.size()-1);

            if (pre_couple[1]>=intervals[i][0])
            {
                temp.remove(temp.size()-1);
                temp.add(new int[]{pre_couple[0],Math.max(intervals[i][1],pre_couple[1])});
            }
            else
            {
                temp.add(new int[]{intervals[i][0],intervals[i][1]});
            }

        }
        int[][] res=new int[temp.size()][2];
        for (int i=0;i<temp.size();i++)
        {
            res[i][0]=temp.get(i)[0];
            res[i][1]=temp.get(i)[1];
        }
//            res[i][]
        return  res;
    }

}

```