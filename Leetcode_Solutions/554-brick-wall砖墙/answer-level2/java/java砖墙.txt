
将除每行最后一块砖之外的每一块砖右边界之和作为hashMap的键，初始值为0，有重复的键，对应的值加1。
行数-Map中最大的值就是直线穿过的最少墙数。


class Solution {
    public int leastBricks(List<List<Integer>> wall) {

        Map<Integer,Integer> timesMap = new HashMap<>();

        int result = 0;

        for(List<Integer> row : wall) {

            Integer sum = 0;

            for(int i=0; i<row.size()-1;  i++) {

                sum += row.get(i);

                Integer times = (times=timesMap.get(sum))==null? 1 : ++times;

                timesMap.put(sum, times);

                if(times > result) {

                    result = times;
                }
            }
        }        
        return wall.size() - result;
    }
}