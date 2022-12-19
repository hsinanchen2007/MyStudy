
做这一题核心思想是先排序后合并，
合并的条件是下一个数组的开头小于等于前一个数组的结尾
合并之后的新数组是两个数组较大的结尾和较小的开头，开头可以通过预先排序确定顺序

做这一题的收获主要是List<int[]>与int[][]的转换，还有lamda表达式的练习
以前碰到输出结果不定但是要求数组输出的话，我会先用list存储，一维数组还好直接toArray，二维数组我就不知道怎么转了，惭愧

```
class Solution {
    public int[][] merge(int[][] intervals) {

        if(intervals.length<2) return intervals;
        Arrays.sort(intervals,(array1,array2) -> (array1[0] - array2[0]));
        List<int[]> ans = new ArrayList();

        int curArray[] = intervals[0];
        for(int[] array : intervals){
            if(array[0] <= curArray[1]){
                curArray[1] = Math.max(array[1],curArray[1]);
            }else{
                ans.add(curArray);
                curArray = array;
            }    
        }
        ans.add(curArray); 
        return ans.toArray(new int[ans.size()][]);
    }
}
```
