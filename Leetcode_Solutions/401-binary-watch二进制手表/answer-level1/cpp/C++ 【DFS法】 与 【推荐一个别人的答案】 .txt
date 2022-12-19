**下面先介绍一个我自己的“DFS+回溯+剪枝“算法，然后再推荐一个我很喜欢的答案，希望对大家有帮助！”**

# DFS

```
vector<string> ans;
vector<string> readBinaryWatch(int num) {
    DFS(num, 0, vector<int>(10));
    return ans;
}
void DFS(int num, int pos, vector<int>time) {
    if (num == 0) {
        int hour = time[0] + 2 * time[1] + 4 * time[2] + 8 * time[3];
        int minute = time[4] + 2 * time[5] + 4 * time[6] + 8 * time[7] + 16 * time[8] + 32 * time[9];
        if (hour < 12 && minute < 60) {
            char buffer[6];
            sprintf_s(buffer, "%d:%.2d", hour, minute);
            ans.push_back(buffer);
        }
        return;
    }
    for (int i = pos; i <= 10 - num; i++) {
        time[i]++;
        DFS(num-1, i + 1, time);
        time[i]--;
    }
}
```

# 解题推荐：

https://leetcode-cn.com/problems/binary-watch/solution/cjian-jian-dan-dan-de-ji-xing-dai-ma-jie-jue-wen-t
这个哥们的算法很美妙，希望大家也喜欢。（这才是暴力美学！）