
看了好多都是计算平均时间都是用：`总时间 / 行程次数` 在一些极端情况下可能溢出。这里介绍一个累加平均值的方法，避免溢出。
累加平均值的公式: 
$$avg_{new}=avg_{pre}*(num_{pre}/(num_{pre}+1))+val_{new}/(num_{pre}+1) $$
其中 $avg_{pre}$ 上一次求得的平均值，$num_{pre}$ 为上次求平均值时的元素个数，$val_{new}$ 新添加的值 $avg_{new}$ 为添加新值后的平均值。

```cpp
class UndergroundSystem {
public:
    
    typedef unordered_map<string, unordered_map<string, pair<float, int>>> AverageTime;// pair<float, int>表示平均路程,求平均时的总数
    AverageTime average_time; // AverageTime[sta1][sta2].first为平均路程, second为求平均时路程数
    unordered_map<int, pair<string, int>> id_to_sta; // id到sta,时间的映射
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        id_to_sta[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [sta_in, sta_in_t] = id_to_sta[id];// 获取入站点 和 入站时间
        int t_delta = t - sta_in_t;// 获取耗时
        // 计算新的平均数，采用累加平均值算法，防止溢出 因为t为10^6时，操作20000次可能会溢出int
        auto [pre_ave_time, pre_ave_count] = average_time[sta_in][stationName];
        float new_ave_time = pre_ave_time * pre_ave_count / (pre_ave_count+1) + (float)t_delta / (pre_ave_count+1);
        // 更新平均时间
        average_time[sta_in][stationName] = make_pair(new_ave_time, pre_ave_count+1);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        if(average_time.find(startStation) == average_time.end())
            return 0.0;
        else
            return average_time[startStation][endStation].first;
    }
};
```
**结果：**
![snipaste_20200329_171744.png](https://pic.leetcode-cn.com/b84828917e486d1c9f7dd3f6445b78c43c6f4b25d43cce1d379c08a5db9a4c61-snipaste_20200329_171744.png)

