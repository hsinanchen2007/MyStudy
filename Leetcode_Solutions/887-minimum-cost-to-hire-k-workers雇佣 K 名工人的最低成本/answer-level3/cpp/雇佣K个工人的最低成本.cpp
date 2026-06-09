### 解题思路
工人的工作质量 quality
工人的最低期望工资 wage

雇佣k个工人
设这k个工人的实际工资为 r[0] , r[1] , .... r[k-1]
实际工资按照工作质量来分配，当质量为n倍，实际工资也为n倍
因此工人们的实际工资有一个公因数 x
实际工资满足 r[i] = quality[i] * x 
工资组为 r[0] + r[1] +r[2] + .... + r[k-1] = x * (quality[0] + ....+ quality[k-1] )

同时实际工资>=期望工资 
r[i]>=wage[i]  即 quality[i] * x >=wage[i]
x >= wage[i] / quality[i]

建立一个大小为N的数组 x[ ]  ， 令 x[i] = wage[i] / quality[i]

要选出k个工人，如果令 x=x[i]
剩下的k-1个工人需要满足 x[p] <= x  ，使 x * quality[p] >=wage[p]
因此对数组 x[ ] 从小到大排序 ，对其从前向后遍历 （i>=k-1开始）
在 x[0] , x[1] ,... x[i] 中选k个工人，使工资组为当前  x 下的最小值
也即是在 x[0] , x[1] ,... x[i-1] 中选 quality[] 最小的k-1个人 

示例1：
quality[ ] = [10,20,5]
wage[ ]= [70,50,30]
x[ ]=[(0,7),(1,2.5),(2,6)]  
排序 >> x[ ]=[(1,2.5),(2,6),(0,7)]
K=2，从i=K-1=1开始遍历
i=1,  x=x[1].second=6， 选K-1=1个quality[] 最小的工人， res=6*(20+5)=150
i=2,  x=x[2].second=7， 选K-1=1个quality[] 最小的工人， res=7*(10+5)=105

示例2：
quality[ ] = [3,1,10,10,1]
wage[ ]= [4,8,2,2,7]
x[ ]=[(0,1.333333),(1,8),(2,0.2),(3,0.2),(4,7)]  
排序 >> x[ ]=[(2,0.2),(3,0.2),(0,1.333333),(4,7),(1,8)]
K=3，从i=K-1=2开始遍历
(1) i=2,  x=x[2].second=1.333333  
选K-1=2个quality[] 最小的工人， res=1.333333(3+10+10)=30.666667  
(2) i=3,  x=x[3].second=7
选K-1=2个quality[] 最小的工人， res=7*(1+3+10)=98
(3) i=4,  x=x[4].second=8
选K-1=2个quality[] 最小的工人， res=8*(1+3+1)=40



### 代码

```cpp
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double,int>> x;
        int N=quality.size();
        for(int i=0;i<N;i++)
           x.push_back({wage[i]*1.0/quality[i]*1.0,quality[i]});
        sort(x.begin(),x.end());
        double res=INT_MAX,temp=0.0;
        priority_queue<int> heap;
        for(auto worker:x){
            heap.push(worker.second);
            temp+=worker.second;
            if(heap.size()>K){
               temp-=heap.top();
               heap.pop();
            }
            if(heap.size()==K)
                res=min(res,temp*worker.first);
             
        }
        return res;
    }
};
```