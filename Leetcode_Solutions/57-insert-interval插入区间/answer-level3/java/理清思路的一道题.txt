### 解题思路
这道题看似不难，但是直觉上，感觉要注意的细节很多。
后面理清思路，谈一谈自己的看法。
1. 新区间可能与数组中的某个（些）区间有交集，可能在数组的范围之外
2. 因为原始的数组是按序的，并且没有重叠，所以我们期望从左到右存储数组中的区间，循环的条件就是我们还没遇到新区间，也就是新区间的左端点 > 数组中当前区间的右端点，这就可以保证我们没遇到新区间。
3. 当我们遇到新区间时，判断当前的区间是否和新区间有重叠
4. 假如有重叠，我们就更新新区间的范围
```
newInterval[0] = Math.min(newInterval[0],intervals[index][0]);
newInterval[1] = Math.max(newInterval[1],intervals[index][1]);
```
5. 重复3，4操作，直到数组中的当前区间和新区间没有重复，我们就存储新区间
6. 最后存储数组中剩余的区间

### 代码

```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int index = 0;
        int len = intervals.length;
        List<int[]> res = new ArrayList<>();
        while (index < len && intervals[index][1] < newInterval[0]){
            res.add(intervals[index]);
            index++;
        }
        //更新新区间，直到没有重复的区域
        while (index < len && isTrue(intervals[index],newInterval)){
            newInterval[0] = Math.min(newInterval[0],intervals[index][0]);
            newInterval[1] = Math.max(newInterval[1],intervals[index][1]);
            index++;
        }
        res.add(newInterval);
        while (index < len){
            res.add(intervals[index]);
            index++;
        }
        int[][] ints = res.toArray(new int[0][]);
        return ints;
    }

    private boolean isTrue(int[] A, int[] B){
        if (A[0] >= B[0] && A[0] <= B[1])
            return true;
        else if (A[1] >= B[0] && A[1] <= B[1])
            return true;
        else  if (B[0] >= A[0] && B[0] <= A[1])
            return true;
        else if (B[1] >= A[0] && B[1] <= A[1])
            return true;
        return false;
    }
}
```