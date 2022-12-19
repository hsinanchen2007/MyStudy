### 解题思路
在heater首尾分别插入-1000000000，INT_MAX就能保证所有的houses都能覆盖，然后判断两个热水器之间的那栋房子能获得热水需要的最小半径即可

### 代码

```cpp
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
		if(!is_sorted(houses.begin(),houses.end()))
			sort(houses.begin(),houses.end());
		if(!is_sorted(heaters.begin(),heaters.end()))
			sort(heaters.begin(),heaters.end());
        int r=0;
		heaters.insert(heaters.begin(),-1000000000);
		heaters.push_back(INT_MAX);
		int i=0,houlen=houses.size();		
		int j=0,healen=heaters.size();
		for(;i<houlen;++i){
			while(!(houses[i]>=heaters[j]&&houses[i]<=heaters[j+1])) ++j;
			r=max(r,min(houses[i]-heaters[j],heaters[j+1]-houses[i]));
		}

		return r;
    }
}; 
```