
感觉官方给出的答案不是最优解，**其实可以构造一个{{区间坐标=>区间次序}}的映射并顺序扫描它，每当得到一个完整的封闭区间时便输出**，来实现O(n)时间的算法，大致过程如下：
第一趟扫描输入的区间数组，**以头尾坐标为key,索引值+1为val**存入一个map中（其中头坐标为正，尾坐标为负，这样就能保证一个完整封闭区间里的坐标值之和一定为0）；
第二趟遍历这个map（这里利用了c++map的有序性），不断累加区间坐标值，每当**坐标值之和为零**时便输出这个区间（即上一次为0之后的key和当前的key），并重新开始下一个区间的扫描。
```c++ []
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size()==0 || intervals.size()==1){
        return intervals;
    }

    map<int,int> orders;
    for(int i=0; i<intervals.size(); i++){
        int s = intervals[i][0];
        int e = intervals[i][1];
        if(orders.find(s)==orders.end()){
            orders[s] = 0;
        }
        if(orders.find(e)==orders.end()){
            orders[e] = 0;
        }
        orders[s] += i+1;
        orders[e] += -i-1;
    }

    int sum = 0;
    vector<vector<int>> ret;
    vector<int> cur;
    for(std::map<int,int>::iterator it=orders.begin(); it!=orders.end(); it++){
        if(sum==0){
            cur.push_back(it->first);
            sum += it->second;
            if(sum==0){
                cur.push_back(it->first);
                ret.push_back(cur);
                cur.clear();
            }
            continue;
        }
        sum += it->second;
        if(sum==0){
            cur.push_back(it->first);
            ret.push_back(cur);
            cur.clear();
        }
    }

    return ret;
}
```
