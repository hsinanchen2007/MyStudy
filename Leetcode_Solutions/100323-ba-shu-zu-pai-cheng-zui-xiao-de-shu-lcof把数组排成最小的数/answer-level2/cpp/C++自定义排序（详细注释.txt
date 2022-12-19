### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string minNumber(vector<int>& nums) {
        if(nums.size()==0) return " ";
        //因为compare是string,string所以要先将nums转化为string再自定义排序
        vector<string> s;
        for(int i=0;i<nums.size();++i)
        {
            s.push_back(to_string(nums[i]));
        }
        sort(s.begin(),s.end(),compare);//自定义排序
        string res;
        for(int i=0;i<s.size();++i)
            res=res+s[i];
        return res;
    }
    static bool compare(string s1,string s2)//自定义比较函数，要将比较函数设置为静态
    //因为sort最后一个排序参数是指针，静态成员函数返回值和普通指针没有区别
    {
        string a=s1+s2;
        string b=s2+s1;
        if(a<b) return true;
        return false;
    }
};
```