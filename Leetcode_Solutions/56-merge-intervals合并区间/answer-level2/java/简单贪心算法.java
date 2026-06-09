### 解题思路
先将数组按照第一个值大小排序，形成有序二维数组，然后从前往后依次合并区间

### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        //利用比较器将数组排序
        Arrays.sort(intervals,new ArrayComparator());
        List<int[]> list=new ArrayList<>();
        int i=0;
        while(i<intervals.length){
            int[] temp=intervals[i];
            //将所有能和当前区间合并的区间合并
            while(i+1<intervals.length && temp[1]>=intervals[i+1][0]){
                temp=new int[]{temp[0],Math.max(temp[1],intervals[i+1][1])};
                i++;
            }
            list.add(temp);
            i++; //进入下一个区间
        }
        return list.toArray(new int[list.size()][]);

    }
    //创建按数组第一个元素大小排序的比较器
    class ArrayComparator implements Comparator<int[]>{
        @Override
        public int compare(int[] a1,int[] a2){
            return a1[0]-a2[0];
        }
    }
}
```