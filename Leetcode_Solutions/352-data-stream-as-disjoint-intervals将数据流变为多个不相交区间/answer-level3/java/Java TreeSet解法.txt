### 解题思路
这个题的思路跟LeetCode_228题"汇总区间"相似，只是输入的数据无序
这里可以采用TreeSet使输入的数据自动排序,然后就可以采用228题的算法了

### 代码

```java
class SummaryRanges {

    TreeSet<Integer> set = null;

    /** Initialize your data structure here. */
    public SummaryRanges() {
        set = new TreeSet<Integer>();
    }
    
    public void addNum(int val) {
        set.add(val);
    }
    
    public int[][] getIntervals() {
        List<int[]> list = new LinkedList<int[]>();
        int[] nums = new int[2];
        Iterator<Integer> it = set.iterator();
        while(it.hasNext()){
            int num = it.next();
            if(set.contains(num-1) && set.contains(num+1)){//num是区间的里面的点
                continue;
            }
            if(!set.contains(num-1) && !set.contains(num+1)){//num是区间单独的点
                nums[0] = num;
                nums[1] = num;
                list.add(nums);
                nums = new int[2];
                continue;
            }
            if(!set.contains(num-1) && set.contains(num+1)){//num是区间的左端点
                nums[0] = num;
                continue;
            }
            if(set.contains(num-1) && !set.contains(num+1)){//num是区间的右端点
                nums[1] = num;
                list.add(nums);
                nums = new int[2];
                continue;
            }
        }
        int len = list.size();
        int[][] res = new int[len][2];
        for(int i=0;i<len;i++){
            res[i][0] = list.get(i)[0];
            res[i][1] = list.get(i)[1];
        }
        return res;
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * int[][] param_2 = obj.getIntervals();
 */
```