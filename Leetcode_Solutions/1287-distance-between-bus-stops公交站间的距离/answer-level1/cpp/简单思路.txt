![image.png](https://pic.leetcode-cn.com/894b81e864b788ab06dfe6d2e2f36fe685c09ac7666a45371f6b7b6293c9507e-image.png)

```
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int s1=0,s2=0;//顺、逆方向的距离
        int i;
        int n=distance.size();
        i=start;
		while(i!=destination){//顺时针 
			s1+=distance[i];
			i=((i+1)%n);
		}
		i=start;
		while(i!=destination){//逆时针 
			i=((i-1+n)%n);
			s2+=distance[i];
		}
		return s1<s2?s1:s2;
    }
};
```
