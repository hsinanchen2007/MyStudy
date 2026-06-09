参考高赞题解，利用C++sort实现自定义排序

```
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> str_num;
        for(int i:nums)
        str_num.push_back(to_string(i));

        sort(str_num.begin(),str_num.end(),cmp);

        string res;
        for(string i:str_num)
        res+=i;

        return res;
    }
    static bool cmp(string a,string b)
    {
        if(a[0]==b[0])
        return a+b<b+a;

        return a[0]<b[0];
    }
};
```
