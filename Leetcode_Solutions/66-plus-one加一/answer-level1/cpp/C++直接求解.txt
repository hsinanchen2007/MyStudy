从个位相加，如果低位无进位，直接更改当前位数据便可直接输出，如果产生仅为则继续循环至无进位，如果出现99....99的情况要考虑添加数位

思路：先拷贝原始数据，从末位开始加一，直到停止进位，后将数据输出
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i,l=digits.size(),pl=1,di;
        vector<int>ans(digits);
        for(i=l-1;i>=0;i--)
        {
            di=digits[i]+pl;//判断当前位数据加后结果
            if(di<10)
            {
                ans[i]=di;
                return ans;//直接输出
            }
            else
            {
                ans[i]=di%10;//取个位继续循环
            }
        }
        ans.insert(ans.begin(),1);//保证99.......99这种循环情况
        return ans;
    }
};
```
