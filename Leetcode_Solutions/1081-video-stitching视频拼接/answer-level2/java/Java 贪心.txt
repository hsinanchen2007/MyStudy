```
public int videoStitching(int[][] clips, int T) {
    int count = 0;
    for (int time = 0; time < T; ) {
        int max = time;
        //每次选择起始时间小于当前时间点而结束时间最晚的视频
        for (int j = 0; j < clips.length; j++) {
            if (clips[j][0] <= time) {
                max = Math.max(max, clips[j][1]);
            }
        }
        //找不到下一个视频返回-1
        if (max == time) {
            return -1;
        }
        count++;
        time = max;
    }
    return count;
}
```
