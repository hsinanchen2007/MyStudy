使用动态规划的方法，我们可以通过一个数组arr来存放到达需要的精力，例如我们需要到达第arr[9]的位置的话，需要到达此处的精力即为cost[0]到cost[8]所需要的最少精力，那么当我们需要从数组的开头走到最后时，只需要判断倒数两个数组的值再加上对应的cost数组的值的和哪个更小即可。
```
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();//获得长度
        vector<int> arr(len,0);
        arr[0]=0;
        arr[1]=0;//到达该两点之前需要的精力都为0，因为可以直接一步或者两步就抵达
        for(int i=2;i<len;i++)
        {
            if(arr[i-1]+cost[i-1]>arr[i-2]+cost[i-2])//比较到达第i个位置之前的第i-1个位置和第i-2个位置哪个需要的精力更少
            {
                arr[i]=arr[i-2]+cost[i-2];
            }
            else
            {
                arr[i]=arr[i-1]+cost[i-1];
            }
        }
        arr[len-1]+=cost[len-1];
        arr[len-2]+=cost[len-2];//因为arr存放的是到达该点之前耗费的精力，所以最后需要加上该点需要消耗的精力
        int sum=arr[len-1]>arr[len-2]?arr[len-2]:arr[len-1];//取最后两个数的最小值即可
        return sum;
    }
};
```