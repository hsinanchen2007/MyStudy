这道题就是模拟盒子打开的过程。 `initialBoxes` 中一定有至少一个盒子，然后以这个盒子为起点不断打开新的盒子。整体就是 BFS 的思路，使用队列保存待打开的盒子。

关键点1：盒子能打开，要么是它本身是开的（`status = 1`），要么是有了它的钥匙

关键点2：BFS 搜索的过程中可能会出现一个盒子打不开，但是后续又找到了这个盒子的遍历的情况，例如第一个测试用例里的盒子 1。这里使用两个队列，第一个队列是常规的 BFS 队列，BFS 中凡是打不开的盒子，先暂时放到第二个队列里。BFS 结束后，再对第二个队列里的盒子进行 BFS 遍历。这个过程的终点应该是**一次 BFS 遍历再也打不开新的盒子**，所以在外面又套了一层循环。

参考代码：

```C++
int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int totalCandies = 0;
    
    queue<int> bq;
    queue<int> bq2;
    for (int b : initialBoxes) {
        bq.push(b);
    }
    unordered_set<int> keyset;
    
    bool hasNewOpen = false;
    do {
        hasNewOpen = false;
        while (!bq.empty()) {
            int box = bq.front(); bq.pop();
            // open this box
            if (status[box] == 1 || keyset.find(box) != keyset.end()) {
                hasNewOpen = true;
                // get candies
                totalCandies += candies[box];
                // get keys
                for (int k : keys[box]) {
                    keyset.insert(k);
                }
                // get boxes
                for (int b : containedBoxes[box]) {
                    bq.push(b);
                }
            } else {
                // no keys currently
                bq2.push(box);
            }
        }
        swap(bq, bq2);
    } while (hasNewOpen);
    
    return totalCandies;
}
```