![image.png](https://pic.leetcode-cn.com/01770e84b7cff45efa389e269f9da17b7b670b2128dda8e2cb730ebdab2f8b74-image.png)
1. 排序前先检查是否已有序对本例有效
2. 加入哨兵可减少特殊情况的代码
3. 为每个house找到其左右近邻供暖器可减少abs函数的开销
```c++
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        const int h1 = houses.size(), h2 = heaters.size();
        if(!is_sorted(houses.begin(),houses.end()))
            sort(houses.begin(),houses.end());
        if(!is_sorted(heaters.begin(),heaters.end()))
            sort(heaters.begin(),heaters.end());
        heaters.push_back(2000000000);
        int r = 0,i = 0;
        if(houses[0]<heaters[0]){
            r = heaters[0] - houses[0];
            if(houses[h1-1]<=heaters[0])
                return r;
            while(houses[++i]<heaters[0]);
        }
        for(int R,j=0;i<h1&&j<h2;++i){
            while(houses[i]<heaters[j]||houses[i]>heaters[j+1])++j;
            r = max(r,min(houses[i]-heaters[j],heaters[j+1]-houses[i]));
        }
        return r;
    }
};
```