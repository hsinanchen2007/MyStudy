### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
	{int num=0;
	 for(int i=0;i<timeSeries.size();i++)
	 {if(i==timeSeries.size()-1){num+=duration;break;}
     if(timeSeries[i+1]-timeSeries[i]>=duration) 
	   {num+=duration;}
	 else
	 { num+=timeSeries[i+1]-timeSeries[i]; }
	   }
	 return num;
    }
};

```