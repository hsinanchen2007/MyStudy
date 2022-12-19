用 [ToLeftTest](https://www.cnblogs.com/wind-chaser/p/10889537.html) 来检测三点是否共线

![WechatIMG14.png](https://pic.leetcode-cn.com/8692b218d2ba6dada998d580dab88ac29043ef20b6ceb3dab852d82e5e69a75c-WechatIMG14.png)


```
bool checkStraightLine(vector<vector<int>> &coordinates) {
    if (coordinates.size() <= 2) return true;

    for (int i = 2; i < coordinates.size(); ++i) {
        int a1 = coordinates[i - 2][0];
        int b1 = coordinates[i - 2][1];
        int a2 = coordinates[i - 1][0];
        int b2 = coordinates[i - 1][1];
        int a3 = coordinates[i][0];
        int b3 = coordinates[i][1];

        // toleft test
        if (a1 * b2 - a2 * b1 + a2 * b3 - a3 * b2 + a3 * b1 - a1 * b3 != 0)
            return false;
    }

    return true;

}
```
