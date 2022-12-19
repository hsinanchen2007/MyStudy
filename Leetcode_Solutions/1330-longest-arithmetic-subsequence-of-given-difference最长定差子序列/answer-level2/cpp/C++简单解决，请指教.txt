```
 int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> maps;
        int maxL = 1;
        for( int i :arr)
        	{
                maps[i]= maps[i-difference]+1;
                maxL = maxL <maps[i]?maps[i]:maxL;
	}
		
		return maxL;
    }
```
请指教，map中KEY对应的VALUE为空时输出0，利用了这点，i对i-difference进行叠加
![image.png](https://pic.leetcode-cn.com/7ffc7d97b6b419a86d85c237e96d867bf9a12d419a5cd5c74146c718706a4e67-image.png)
