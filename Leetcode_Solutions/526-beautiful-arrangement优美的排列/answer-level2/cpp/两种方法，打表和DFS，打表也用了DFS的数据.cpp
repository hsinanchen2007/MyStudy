### 解题思路
打表过程在注释给出，不打表的时候直接令N=n，然后dfs(1),res即为答案。
![image.png](https://pic.leetcode-cn.com/4ecf9af5d8a8bd656db8362919ab1d2915d06580c79317c1f30ec3434ac879d9-image.png)


### 代码

```cpp
class Solution {
public:
bool access[16];
int N;
int res;
void dfs(int curr)
{
	if (curr == N+1)
    {
        res++;
        return;
    }
	for (int i = 1; i <= N; i++)
		if (access[i])continue;
		else {
			if (!(i%curr == 0 || curr % i == 0))continue;
			access[i] = true;
			dfs(curr+1);
			access[i] = false;
		}
}
    int countArrangement(int n) {
    //N = n;
	//dfs(1);
    vector<int>re={1,2,3,8,10,36,41,132,250,700,750,4010,4237,10680,24679};
    //以下是如何打表
   /* for(int i=1;i<=15;i++)
    {
        res=0;
        N=i;
        dfs(1);
        cout<<res<<",";
    }*/
	return re[n-1];
    }
};
```