很直接很暴力的直接遍历的同时进行翻转
```
class Solution 
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
    {
        for(auto &vec:A)
        {
            reverse(vec.begin(),vec.end());
            for(auto &elm:vec)
            {
                if(elm==0)
                {
                    elm=1;
                }
                else
                {
                    elm=0;
                }
            }
        }
        return A;
    }
};
```


