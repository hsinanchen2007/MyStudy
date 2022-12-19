直接模拟分糖果的过程
```
vector<int> distributeCandies(int candies, int num_people) {
        int cnt = 1;
        vector<int> ans(num_people,0);
        int i = 0;
        for(; candies >= cnt;)
        {
            ans[i] += cnt;
            candies -= cnt;
            cnt++;
            if(i == num_people - 1) i = 0;
            else i++;
        }
        if(candies) ans[i] += candies; 
        return ans;
    }
```
时间复杂度：O(N)
空间复杂度：O(1) 除去答案数组