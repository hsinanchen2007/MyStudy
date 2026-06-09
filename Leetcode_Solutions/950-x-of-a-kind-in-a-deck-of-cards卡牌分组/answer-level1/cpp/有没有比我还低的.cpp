### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int gcd(int a,int b) //辗转相除法
    {
        return b==0?a:gcd(b,a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        if(!deck.size())return false;
        map<int,int> mymap;
        for(auto c:deck)
        {
            map<int,int>::iterator it = mymap.find(c);
            if(it==mymap.end())
            {
                mymap[c]=1;
            }
            else
            {
                (it->second)++;
            }
        }
        vector <int> arr;
        for( map<int,int>::iterator it = mymap.begin();it!=mymap.end();it++)
        {
            arr.push_back(it->second);
        }
        sort(arr.begin(),arr.end());
        int X=arr[0];
        if(X==1)return false;
        for(int i=1;i<arr.size();i++)
        {
            X = gcd(X,arr[i]);
            if(X==1)return false;
        }
        return true;

    }
};
```
![image.png](https://pic.leetcode-cn.com/d67b7d8377550a8b68fc62a8f5b3f838ab8ff16f45840baf4054cacd18d5a4dc-image.png)