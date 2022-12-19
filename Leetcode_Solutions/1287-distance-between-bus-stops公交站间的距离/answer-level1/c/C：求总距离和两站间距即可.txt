思路：
求所有站点总距离，求两站间距（注意start和destination不一定是start < destination）
比较两站间距和（总距离-间距）的另一个方向距离，返回小的结果即可
```
int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    int one_direction = 0;
    int total = 0;
    int smaller = (start < destination ? start : destination);
    int bigger = (start > destination ? start : destination);
    int i;
    for (i = 0; i < distanceSize; i++) {
        total += distance[i];
    }
    for (i = smaller; i < bigger; i++) {
        one_direction += distance[i];
    }
    return one_direction < total - one_direction ? one_direction : total - one_direction;
}
```
*过程：
一开始想当然认为start<destination，求两个距离（start——destination）和（destination——start）
还觉得需要求余操作处理下标，比较麻烦，还是求快而没有深刻思考的结果。
进一步分析，距离只有两个且两站的先后顺序不一定，由此确定了解题方案，
求间距和求总距离算差值可以直接得到结果。