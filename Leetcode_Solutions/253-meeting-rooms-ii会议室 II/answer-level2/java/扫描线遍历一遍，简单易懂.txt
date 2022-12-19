### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    // 计算至少需要多少间会议室，才能满足这些会议安排 ==> 最多同时开多少个会议 ==> 扫描线
    // 每当有会议加入时，meetings 加1， 每当有会议退出时，meetings 减1。求出meetings的最大值即可。
    public int minMeetingRooms(int[][] intervals) {
        // 我们存进一个list中，并且标记每个会议的开始和结束，0代表会议开始，1代表会议结束
        List<int[]> list = new ArrayList<>();
        for (int[] interval : intervals) {
            list.add(new int[]{interval[0], 0});
            list.add(new int[]{interval[1], 1});
        }
        // 对它按照时间开始时间升序排序，如果开始时间一样，结束的在前！不然要重复算的，比如{{1, 13}, {13, 15}};，一定是结束的13在前
        list.sort((o1, o2) -> o1[0] == o2[0] ? o2[1] - o1[1] : o1[0] - o2[0]);
        int res = 0;
        int rooms = 0;
        for (int[] interval : list) {
            // 如果标记为开始，room++
            if (interval[1] == 0) {
                rooms++;
                res = Math.max(res, rooms);
            } else {
                rooms--;
            }
        }
        return res;
    }
}
```