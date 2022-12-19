
### 代码

```cpp
class Solution 
{
public:
    int minSetSize(vector<int>& arr) 
    {
        int n=arr.size();
        if(arr.size()==2) return 1;

        int ans=0;

        map<int,int> help;
        for(int a:arr) help[a]++;

        vector<int> sum;
        for(auto h:help) sum.push_back(h.second);
        sort(sum.begin(),sum.end());
        reverse(sum.begin(),sum.end());
        int temp=n;
        int index=0;
        while(temp>n/2)
        {
            temp-=sum[index++];
            ans++;
        }
        
        return ans;
    }
};
```