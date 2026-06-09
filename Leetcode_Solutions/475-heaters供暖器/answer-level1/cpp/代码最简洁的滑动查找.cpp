思路：为每个房屋找到最近的供暖器，并记录距离；在所有最近的里挑最大的距离返回
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int index=0,max=0;
        for(int i=0;i<houses.size();i++)
        {
            if(index+1<heaters.size() && abs(heaters[index]-houses[i])>=abs(heaters[index+1]-houses[i]) )
            {
                index++;
                i--;
                continue;
            }  
            max>=abs(heaters[index]-houses[i])?:max=abs(heaters[index]-houses[i]);
        }
        return max;
    }
};