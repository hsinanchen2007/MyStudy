    看了一片评论区，基本都说得是排序解法，我来说个逻辑简单的暴力解法，就是从左到右依次合并，直接上代码吧
'''
public class Merge {

    public int[][] merge(int[][] intervals) {
        int len = intervals.length;
        if(len == 0){
            return new int[0][0];
        }
        // 表示已被合并的位置 
        boolean[] memo = new boolean[intervals.length];
        // 开始合并
        divide(intervals,0,intervals.length-1,memo);
        int n = 0;
        List<int[]> list = new ArrayList<>();
        for (int i = 0; i < memo.length; i++) {
            if(!memo[i]){
                list.add(intervals[i]);
            }
        }
        return list.toArray(new int[list.size()][2]);
    }

    public void divide(int[][] intervals,int left,int right,boolean[] memo){
        // 从左到右依次与右端区间作比较
        for (int i = left; i <= right; i++) {
            // 已合并区间直接跳过
            if(memo[i]){
                continue;
            }
            // 创建待被合并区域备份
            int[] temp = intervals[i];
            // 被合并区域索引
            int n = i;
            for (int j = i + 1; j <= right; j++) {
                // 已被合并区域直接跳过
                if(memo[j]){
                    continue;
                }
                List<Integer> result = new ArrayList<>();
                if(canMerge(temp,intervals[j],result)){
                    memo[n] = true;
                    intervals[j] = new int[]{result.get(0),result.get(1)};
                    temp = intervals[j];
                    n = j;
                }
            }
        }

    }
    
    // 判断是否能合并，并返回合并结果
    public boolean canMerge(int[] left, int[] right, List<Integer> result){
        if(left[0] >= right[0] && left[0] <= right[1]){
            result.add(right[0]);
            result.add(Math.max(left[1],right[1]));
            return true;
        }
        if(right[0] >= left[0] && right[0] <= left[1]){
            result.add(left[0]);
            result.add(Math.max(left[1],right[1]));
            return true;
        }
        return false;
    }
}
'''