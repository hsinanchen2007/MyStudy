### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:  //C++  STL sort()的使用
    static bool cmp1(const string &x,const string &y){  //这里要加static,否则无效使用非静态成员函数
       return x+y>y+x;    
   }
    string largestNumber(vector<int>& nums) {
        if(nums.size()==0) return "";
        vector<string>res;
        string ans;
        for(int i=0;i<nums.size();i++){
            res.push_back(to_string(nums[i]));
        } 
        /*
        sort(res.begin(),res.end(),[](const string& x, const string& y) {  //lambda表达式(匿名函数的使用)
            return x + y > y + x;});//x为后面元素，y为前面元素，return true则将x移动到前面
        */
        sort(res.begin(),res.end(),cmp1);
        if(res[0]=="0") return "0";
        for(auto a : res){
            ans+=a;
        }
        return ans;
    }
};
```