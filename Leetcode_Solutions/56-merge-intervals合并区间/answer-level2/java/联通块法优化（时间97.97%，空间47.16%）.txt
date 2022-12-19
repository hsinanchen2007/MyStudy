### 解题思路

定义`List<int[]> mergedList`记录已合并区间。

遍历所有区间与已合并区间进行合并，无法合并则加入`list`

合并成功需要处理`mergedList`中的所有区间，可能导致新的合并：`list`中的`[1,3]`,`[4,6]`可能因为`[2,5]`加入而产生合并

### 代码

```java
class Solution {


    // 判断B区间是否可以与A区间重合，并合并，如果能重合返回true，否则返回false
    public boolean mergeIntoA(int[] A, int[] B){
        if((B[0] >= A[0] && B[0] <= A[1]) // 有交叉， B在前
                || (B[1] >= A[0] && B[1] <= A[1]) // 有交叉， A在前
                || (B[0] <= A[0] && B[1] >= A[1]) // B包含A
                || (A[0] <= B[0] && A[1] >= B[1]) // A包含B
                ){
            A[0] = Math.min(B[0], A[0]);
            A[1] = Math.max(B[1], A[1]);
            return true;
        }
        return false;
    }

    public int[][] merge(int[][] intervals) {
        if(intervals.length < 2){
            return intervals;
        }

        // 已合并区间列表
        List<int[]> mergedList = new ArrayList<>();
        // 添加第一个区间
        mergedList.add(intervals[0]);

        // 循环所有区间
        for(int i = 1 ; i < intervals.length; i++){
            // 记录区间是否可以和已合并的区间进行合并
            boolean merged = false;
            // 判断区间是否可以和已合并的区间进行合并
            for(int j = 0 ; j < mergedList.size() ; j++){
                // 当前已合并区间
                int[] arr = mergedList.get(j);
                // 如果可以合并
                if(mergeIntoA(arr, intervals[i])){
                    // 记录已经合并
                    merged = true;
                    // 遍历已合并区间的所有区间，和合并后的新区间进行合并
                    Iterator<int[]> iterator = mergedList.iterator();
                    while (iterator.hasNext()){
                        int[] others = iterator.next();
                        // 当前区间不做处理
                        if(arr == others){
                            continue;
                        }
                        // 如果合并成功，移除这个区间（两个区间本来不交叉，引入新区间导致重合）
                        if(mergeIntoA(arr, others)){
                            iterator.remove();
                        }
                    }
                }
            }
            // 如果没有区间合并，当前区间添加到合并列表
            if(!merged){
                mergedList.add(intervals[i]);
            }
        }

        int[][] result = new int[mergedList.size()][2];
        return mergedList.toArray(result);
    }

}
```