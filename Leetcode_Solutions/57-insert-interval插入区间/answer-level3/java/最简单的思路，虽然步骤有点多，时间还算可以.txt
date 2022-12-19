### 思路

 //整体思路
    //时间复杂度O（n），空间复杂度O（n）
    //由于原先是排好序的区间，所以就开始遍历
    //1.如果插入的区间比当前指针（index i）指向的区间整体要大那么不需要继续操作，注意当指针已经指向最后面则说明需要直接插入到结果集
    //2.如果插入的区间整体比当前指向的区间说明可以直接插入，则直接退出循环
    //3.如果插入的区间被包含在当前指向的区间说明不需要做任何处理直接返回即可
    //4.当插入区间包含了当前区间，此时只需要将当前区间的左边界设为插入区间的左边界，右边界要么设置下一个区间的左边界，要么设置为插入区间的右边界（当插入区间的右边界小于下一个区间的左边界）
    //5.当插入区间有一部分被包含在当前区间有一部分大于当前区间则按照步骤4处理即可，只是不需要设置当前区间的左边界
    //注意步骤4 5中当当前区间为最后区间时 可以直接将右边界设置为插入区间的右边界

    //此时只需要合并区间即可，因为可以合并的区间必然是当前区间的右边界等于下一个区间的左边界，所以很简单
    //合并完区间之后还需要判断插入区间是不是需要直接插入如果是则插入到按顺序的位置。
### 代码

```java
class Solution {

   
   public int[][] insert(int[][] intervals, int[] newInterval) {
        if(newInterval.length<=1)return intervals;
        if(intervals.length==0){
            int[][] finalRes = new int[1][2];
            finalRes[0][0] = newInterval[0];
            finalRes[0][1] = newInterval[1];
            return finalRes;
        }
        boolean needIn = false;
        for(int i=0;i<intervals.length;i++){
            //当插入区间在当前区间之内，则可以直接返回
            if (newInterval[0]>intervals[i][1]){
                if(i+1==intervals.length)needIn = true;
                continue;
            }
            else if(newInterval[0]>=intervals[i][0] && newInterval[1]<=intervals[i][1]){
                    break;
            }else if(newInterval[0]<intervals[i][0] && newInterval[1]<intervals[i][0]){
                needIn = true;
                break;
            }else if(newInterval[0]<intervals[i][0] && newInterval[1]<=intervals[i][1]){
                intervals[i][0] = newInterval[0];
                break;
            }else if(newInterval[0]<intervals[i][0] && newInterval[1]>=intervals[i][1]){
                intervals[i][0] = newInterval[0];
                if(i+1<intervals.length && newInterval[1]<=intervals[1+i][0]){
                    intervals[i][1] = newInterval[1];
                    break;
                }else if(i+1==intervals.length){
                    intervals[i][1] = newInterval[1];
                    break;    
                }else{
                    intervals[i][1] = intervals[i+1][0];
                    newInterval[0] = intervals[i+1][0];
                }

            }else if(newInterval[0]>=intervals[i][0] && newInterval[1]>intervals[i][1]){
                if(i+1<intervals.length &&newInterval[1]<=intervals[1+i][0]){
                    intervals[i][1] = newInterval[1];
                    break;
                }else if(i+1==intervals.length){
                    intervals[i][1] = newInterval[1];
                    break;    
                }
                else {
                    intervals[i][1] = intervals[i+1][0];
                    newInterval[0] = intervals[i+1][0];                   
                }
            }
        }

        int res[]  = new int[intervals.length *2+2];
        int index = 0;
        for(int i=0;i<intervals.length;i++){
            if(i+1<intervals.length && intervals[i][1]==intervals[i+1][0]){
                intervals[i+1][0] = intervals[i][0];
            }else{
                res[index++] = intervals[i][0];
                res[index++] = intervals[i][1];
            }
        }

        if(needIn==true){
           index+=2;
        }
        int[][] finalRes  = new int[index/2][2];
        index = 0;
        boolean oneFlag = false; 
        for(int i=0;i<finalRes.length;i++){               
            if((newInterval[0]<res[index]||(i+1==finalRes.length )) && oneFlag ==false &&needIn==true) {
                finalRes[i][0] = newInterval[0];
                finalRes[i][1] = newInterval[1];
                oneFlag = true;
                continue;
            }
            finalRes[i][0] = res[index++];
            finalRes[i][1]  = res[index++];
        }
        return finalRes;

   }


}

```