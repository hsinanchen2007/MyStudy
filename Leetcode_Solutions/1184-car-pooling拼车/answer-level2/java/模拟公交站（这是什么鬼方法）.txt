提交结果：
        执行用时 :1 ms, 在所有 java 提交中击败了100.00% 的用户
        内存消耗 :40 MB, 在所有 java 提交中击败了100.00%的用户
思路：
        因为限制了最长距离为1000，我假设某一个数字是一个公交站牌，创建长度为1001的数组，
        然后遍历trips数组，统计每个位置需要上车或者下车的人数，然后一站一站开，看是否有
        哪一站会出现超载的情况。
代码：
```
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int distance[]=new int [1001];//每个位置最终上车人数或者下车人数
        int tripLength = trips.length;
        int total=0;
        for (int i = 0; i < tripLength; i++) {
            distance[trips[i][1]]+=trips[i][0];//这个位置有人要上车
            distance[trips[i][2]]-=trips[i][0];//这个位置有人要下车
        }
        for (int i = 0; i <= 1000; i++) {
            total+=distance[i];
            if (total>capacity)//在某个位置，需要坐车的人数大于限载
                return false;
        }
        return true;    
    }
}
```
