## 兔子最少的情况
首先报不同答案的一定是不同颜色的
报相同答案的兔子数量有以下两种情况
1. 若该答案总数(即报的答案+1)大于这个答案出现在数组出现的次数，我们可以把所有报该答案的兔子当作同一种颜色的
2. 反之，若该答案总数小于等于出现的次数，我们按照“向上取整”这个方式处理。报该答案的兔子总数最少为:
$$总数[一个颜色有多少只]\times 向上取整(出现次数/总数)[最少出现的颜色]$$

## ceil函数
ceil() 向上取整，即求不小于某个数的最小整数，其原型为：
`double ceil (double x);`

最后使用unordered_map容器节省空间。

```cpp
class Solution {
public:
    int numRabbits(vector<int>& answers)
    {
        unordered_map<int,int>count;
        for(int ans : answers){
            if(count.find(ans)!=count.end())
                count[ans]++;
            else
                count.insert({ans,1});
        }
        int sum = 0;
        for(auto it=count.begin();it!=count.end();++it)
        {
            sum += (it->first + 1) * ceil(it->second * 1.0 / (it->first + 1));
        }
        return sum;
    }
};

```