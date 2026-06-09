1. 将字符按出现的次数降序排列
2. 按照先奇位再偶位(或先偶再奇)依次填充即可

![image.png](https://pic.leetcode-cn.com/93b90c017d3905a5fcc2f86cb3366ad1cbb06dc88897d1796074220320b8f932-image.png)


```
bool cmp(pair<char,int>& p1, pair<char,int>& p2)
{
    return p1.second > p2.second;
}
class Solution {
public:
    string reorganizeString(string S) {
        map<char,int> mp;
        int maxn;
        for(auto ch : S) 
        {
            mp[ch]++;
            maxn = max(maxn, mp[ch]);
        }
        if(maxn > (S.size() + 1) / 2) return "";
        vector<pair<char,int>> arr(mp.begin(),mp.end());
        sort(arr.begin(),arr.end(), cmp);
        string res = S;
        int odd = 1, even = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            while(arr[i].second && even < S.size())
            {
                res[even] = arr[i].first;
                arr[i].second--;
                even += 2;                
            }
            while(arr[i].second)
            {
                res[odd] = arr[i].first;
                arr[i].second--;
                odd += 2;
            }
        }
        return res;
    }
};
```
