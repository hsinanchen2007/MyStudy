设a[i]表示第i个航班预订的座位数。

定义一个差分数组tag[]，tag[i]表示第i个航班与第i-1个航班预订座位的差，即tag[i] = a[i] - a[i - 1]。

这样，我们每次扫描到[i, j, k]，就只需要将tag[i]增加k，tag[j + 1]减少k即可。

最后，计算a[i] = a[i - 1] + tag[i]，返回a即可。

给出代码：
```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int> >& bookings, int n) {
        int tag[20003], len = bookings.size();//定义tag数组并计算预订表的长度
        vector<int>a(n, 0);//定义一个长度为n且值为0的动态数组
        memset(tag, 0, sizeof(tag));//清零tag数组
        for (int i = 0; i < len; i++) {//扫描每一个预订记录
            tag[bookings[i][0]] += bookings[i][2];//对tag数组进行操作
            tag[bookings[i][1] + 1] -= bookings[i][2];
        }
        for (int i = 0; i < n; i++) {//计算每趟航班预订的座位数
            if (i == 0) a[i] = tag[i + 1];
            else a[i] = a[i - 1] + tag[i + 1];
        }
        return a;//直接返回即可
    }
};
```