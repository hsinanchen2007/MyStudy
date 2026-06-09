本题中，给出两个站点，可以得知，两个方向的距离之和为站点环形总长度，所以首要是要得知站点的总长度，
其次，因为两个站点给出的位置不固定，若两个站点逆时针方向中间站点少，而顺时针方向中间站点多，则从效率角度上来说，应当以站点少的部分进行合计，提高效率
# 汇总为：
1. 如果两个站点为同一个站点，则可以直接返回0
2. 计算所有站点环形最长长度
3. 将两个站点判断最短距离为顺时针还是逆时针，按照不同方向进行合计值
4. 判断计算出的距离同剩余距离的最小值即可
# 详细代码如下：
```
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        if (start == destination) {
            return 0;
        }
        // 如果给出的两个站点，开始站点在结束站点之后，则交换一下两个站点的位置
        if (start > destination) {
            int temp = start;
            start = destination;
            destination = temp;
        }

        int minDis = 0;
        int maxLen = 0;
        //得到环形累计长度
        for (int i = 0; i < distance.length; i++) {
            maxLen += distance[i];
        }
        // 判断是顺时针还是逆时针，如果两个站点的距离大于所有站点个数的一半，则逆时针，否则顺时针
        if ((destination - start) > distance.length / 2) {
            for (int i = destination; i < distance.length; i++) {
                minDis += distance[i];
            }

            for (int i = 0; i < start; i++) {
                minDis += distance[i];
            }
        } else {
            for (int i = start; i < destination; i++) {
                minDis += distance[i];
            }
        }

        minDis = maxLen - minDis > minDis ? minDis : maxLen - minDis;
        return minDis;
    }
```
![156354298332399_zh-CN.png](https://pic.leetcode-cn.com/22267071198cebfd5c1288c58e06b12c87930a0b8597b01c8bb10a40e0c96c9a-156354298332399_zh-CN.png)