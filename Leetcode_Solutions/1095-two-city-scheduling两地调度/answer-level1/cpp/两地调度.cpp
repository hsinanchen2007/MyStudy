#  两地调度
公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。

返回将每个人都飞到某座城市的**最低费用**，要求每个城市都**有 N 人**抵达。

 

示例：

```
输入：[[10,20],[30,200],[400,50],[30,20]]
输出：110
解释：
第一个人去 A 市，费用为 10。
第二个人去 A 市，费用为 30。
第三个人去 B 市，费用为 50。
第四个人去 B 市，费用为 20。

最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
```

提示：

1 <= costs.length <= 100
costs.length 为偶数
1 <= costs[i][0], costs[i][1] <= 1000

<hr>

##  解：
注：
- A市和B市均有N人到达
- 要所有人都飞往某座城市得最低费用

###  思路：
我们求得飞往两地之间费用得差值，从差值最大得先分配

###  实现代码：

```
class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>&b)//根据差值降序排序
    {
        return a[2]>b[2];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        for(int i=0;i<n;i++)//求差值
        {
            int temp=0;
            temp=abs(costs[i][0]-costs[i][1]);
            costs[i].push_back(temp);
        }
        sort(costs.begin(),costs.end(),cmp);
        int minsum=0;
        int a1=0;
        int b1=0;
        for(int i=0;i<n;i++)
        {
            if(costs[i][0]<costs[i][1])
            {
                minsum+=costs[i][0];
                a1++;
            }
            else
            {
                minsum+=costs[i][1];
                b1++;
            }
            if(a1==n/2 || b1==n/2)
                break;
        }
        if(a1==n/2)
        {
            for(int i=a1+b1;i<n;i++)
            {
                minsum+=costs[i][1];
            }
        }
        else
        {
            for(int i=a1+b1;i<n;i++)
            {
                minsum+=costs[i][0];
            }
        }
        return minsum;
    }
};
```

