### 解题思路
个人见解:
维护两个list,分别是原始记录和二重预订;核心函数是比较两个线段是否重叠及获取重叠区域
当有一个新的预定时,首先检查二重预定list,如果判断存在重复,则返回false;否则通过与原始记录list比较,来更新二重预定list,然后将其加入原始记录list

### 代码

```cpp
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        records.clear();
        intersects.clear();
    }
    
    typedef pair<int,int> interval;
    interval find_repeat(interval &i1, interval &i2)
    {
        interval i;
        i.first = max(i1.first, i2.first);
        i.second = min(i1.second, i2.second);
        return i;
    }
    bool real_interval(interval &i)
    {
        if (i.first < i.second)
            return true;
        else
            return false;
    }
    vector<interval> records;
    vector<interval> intersects;

    bool book(int start, int end) {
        interval i;
        i.first = start;
        i.second = end;
        for (auto intersect : intersects)
        {
            interval result = find_repeat(i, intersect);
            if (real_interval(result))
                return false;
        }    

        for (auto record : records)
        {
            interval result = find_repeat(i, record);
            if (real_interval(result))
                intersects.push_back(result);
        }   
        records.push_back(i);

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
```