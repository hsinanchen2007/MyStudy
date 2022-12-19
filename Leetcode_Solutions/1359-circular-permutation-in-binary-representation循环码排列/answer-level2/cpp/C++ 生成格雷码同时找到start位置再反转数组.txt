根据格雷码的规律先生成格雷码
res[i]=i^(i>>1);
同时找到start的位置
在通过reverse反转
```
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
    vector<int> res(1<<n);
    int index=0;
    for(int i=0;i<1<<n;++i)
    {
        res[i]=i^(i>>1);
        if(res[i] == start)
        {
            index=i;
        }
    }
    reverse(res.begin()+index,res.end());
    reverse(res.begin(),res.end());
    reverse(res.end()-index,res.end());
    return res;
    }
};
```
