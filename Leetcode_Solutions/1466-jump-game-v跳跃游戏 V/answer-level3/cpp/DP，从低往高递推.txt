- 首先根据题意，只能往低了跳，且中间不能遇到比我高的
- 用 dp[i] 表示从 i 开始跳，最多可以跳的台阶数
- 那么 dp 需要从底的开始往高的计算，所以要先排序


```
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int i, j, n = arr.size(), idx;
        vector<int> dp(n, 0);//dp数组
        multimap<int, int> m;
        for (i = 0; i < n; i++)
        	m.insert(make_pair(arr[i],i));//map有序，默认升序，按数值排序了
        for(auto& it : m)
        {	//从低到高开始dp
        	idx = it.second;//下标
        	if(dp[idx] == 0)//dp[idx]没有填写过
        	{
        		dp[idx] = 1;//至少为1，自己本身
        		for(j = idx-1; j >= idx-d && j>=0 && arr[idx] > arr[j]; j--)
        		{	//往左边跳，遇到比我高的停止
	        		dp[idx] = max(dp[idx], 1+dp[j]);
        		}
        		for(j = idx+1; j <= idx+d && j<n && arr[idx] > arr[j]; j++)
        		{	//往右边跳，遇到比我高的停止
	        		dp[idx] = max(dp[idx], 1+dp[j]);
        		}
        	}
        }
        return *max_element(dp.begin(),dp.end());//取最大值
    }
};

```
[https://michael.blog.csdn.net/article/details/104149099](https://michael.blog.csdn.net/article/details/104149099)

![image.png](https://pic.leetcode-cn.com/b75d1f27ba6f45dc4b0fbbe0eb87b304a0f32a42dc8e09b32beb8676aeef1013-image.png)
