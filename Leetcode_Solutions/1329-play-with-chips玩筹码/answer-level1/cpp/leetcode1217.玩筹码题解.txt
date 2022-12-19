题意是计算筹码移动的最小步数，一开始我看测试数据，以为限制移动的次数，一个筹码只能移动一次，wa一次才发现可以移动多次，根据题意我们可以知道，筹码移动只有两种状态，因为位置相差为2的筹码代价为0，所以可以把所有大于2的位置统一移动到0，1两个位置，这样就简化为判断0，1两个位置筹码的大小的问题，
代码如下：
```
int minCostToMoveChips(vector<int> &chips)
{
    int num[2];
    sort(chips.begin(), chips.end());
    memset(num, 0, sizeof(num));
    int min = chips[0];
    for(auto chip:chips)
        num[(chip-min)%2]++;
    return num[0] < num[1] ? num[0] : num[1];
}
```
