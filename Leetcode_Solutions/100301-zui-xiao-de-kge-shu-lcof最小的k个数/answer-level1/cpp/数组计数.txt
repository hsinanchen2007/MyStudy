### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
int vis[10005]={0};
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        int lens=(int)arr.size();
        for(int i=0;i<lens;i++)
        {
            ++vis[arr[i]];
        }
        int cnt=0;
        while(k)
        {
            --k;
            while(!vis[cnt]) ++cnt;
            ans.push_back(cnt);
            --vis[cnt];
        }
        return ans;
    }
};
```