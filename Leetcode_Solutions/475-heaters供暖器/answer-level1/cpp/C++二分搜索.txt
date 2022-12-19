本题用二分搜索，但是二分搜索用在哪呢？这个才是关键。
首先，houses是需要被遍历的，因此二分搜索就用于快速查找到与house最近的heater。
这就是本题二分法的用处，一开始没有捋清这个思路，所以感觉无从下手。
本题还发现：houses.erase(houses.begin()+0)删除第一个元素非常费时间，
所以最后while循环条件用while(i<houses.size())，
而不能使用while(houses.size())
也算是一个收获。
贴代码：
```
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int maxr=0;//我想用于存储当前半径最大值
        int a = 0;
        int b = heaters.size()-1;
        int tem = (a+b)/2;
        int i=0;
        while(i<houses.size()){
            //存储加热当前屋子所需的最小加热半径
            if(b-a==0){tem = min( abs(heaters[a]-houses[i]),abs(heaters[b]-houses[i]) );++i;}
            while(b-a>1){
            if(heaters[tem]==houses[i]){tem=0;++i;break;}
            else if(heaters[tem]<houses[i]) a=tem;//tem过小，增大a
            else b=tem;//tem过大,减小b
            tem =(a+b)/2;
            }
            if(b-a==1){tem = min( abs(heaters[a]-houses[i]),abs(heaters[b]-houses[i]) );++i;}
            maxr = max(maxr,tem);//存储整体加热器最大的所需半径
            a = 0;
            b = heaters.size()-1;
            tem = (a+b)/2;
        }
        return maxr;
    }
};
```
