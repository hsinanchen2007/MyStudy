### 解题思路
string num用来保存当前进行到各个数字键的第几个字母

### 代码

```cpp
class Solution {
public:
    string a[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    int high[10]={0,0,3,3,3,3,3,4,3,4};
    void backtrace(string d,int start,string num,string str)
    {
        string tmp;
        if(start==d.length()){
            if(str.length()==d.length())
            ans.push_back(str);
            return;
        }
        num[d[start]-'0']='0';
        for(int i=start;i<d.length();i++)
        {
            int k=d[i]-'0';
            while(num[k]-'0'<high[k])
            {
               tmp=str;
               str+=a[k][num[k]-'0'];
               num[k]++;
               backtrace(d,i+1,num,str);
               str=tmp;   
            }
            
        }
    }
    vector<string> letterCombinations(string digits) {
        //int num[10]={0};
        if(digits.length()==0)return ans;
        string num="0000000000";
        backtrace(digits,0,num,"");
        return ans;
    }
};
```