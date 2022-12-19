理解H指数：所有满足H指数定义的数的最大值。所以也就是要寻找不满足H指数定义的最小值。

1）首先对列表进行排序
2）判断当前数是否满足H指数定义
```c++
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if(!size) return NULL;
        std::sort(citations.begin(), citations.end());
        int h = 0;
        while(h+1<=citations[size-1-h]) {
            h++; 
            if(h==size) break;
        }
        return h;
    }
};
```
