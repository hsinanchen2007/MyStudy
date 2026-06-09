```
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
	int n = time.size();
	int res = 0;
    vector<int> m(60,0);
	for (int i = 0; i < n; i++)
	{
		time[i] %= 60;
        m[time[i]]++;
	}
    for (int i = 0; i <= 30; i++)
	{
        if(i==0||i==30) res+=m[i]*(m[i]-1)/2;
        else res+=m[i]*m[60-i];
	}
	return res;
    }
};
```
