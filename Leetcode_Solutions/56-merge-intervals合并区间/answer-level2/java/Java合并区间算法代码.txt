### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public int[][] merge(int[][] intervals) {
        //实现二维数组区间合并
       int[] cur={0,0};//临时数组用来存在方中间结果
        List<int[]> list=new ArrayList<>();
        
        if(intervals.length!=0)//这种判断包含int arr={};的情况
        {


            Arrays.sort(intervals, new Comparator<int[]>() {
                @Override
                public int compare(int[] ints, int[] t1) {
                    //按首元素降序return t1[0]-ints[0];
                    //首元素相通，按照次元素降序排列
                    if (ints[0] == t1[0]) {
                        return ints[1] - t1[1];
                    } else {
                        return ints[0] - t1[0];
                    }

                }
            });
            /*System.out.println("排序之后"+intervals.length);
            for (int[] brry:intervals
            ) {
                System.out.println(brry[0]+""+","+brry[1]);

            }*/
            
            cur=intervals[0];//初始化cur
            
            for(int i=0;i<intervals.length;i++){
                
                if(intervals[i][0]>cur[1])//线段无交集
                {
                    list.add(cur);//无交集的cur元素存入list
                    cur=intervals[i];//产生新的cur
                }else {
                    //有交集，更新cur[1]
                    cur[1]=Math.max(intervals[i][1],cur[1]);
                }
                
                
            }

            list.add(cur);//出循环之后记得要将cur加入到list末尾
            //list转存如结果数组
            int[][] res=new int[list.size()][2];
            for (int i=0;i<list.size();i++) {
                res[i]=list.get(i);
                
            }
            return res;
            
            
        }
            return intervals;
        
        
            

        
    }

}
```