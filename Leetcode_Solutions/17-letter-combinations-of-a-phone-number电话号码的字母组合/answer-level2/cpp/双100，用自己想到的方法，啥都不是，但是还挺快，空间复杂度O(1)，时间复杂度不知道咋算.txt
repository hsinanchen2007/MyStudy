### 解题思路
    每次读入一个字符和已有的字符串一个一个拼接并插入，留下最后一个不做拼接；
    因为只要把最后一个字符添加在前面本来就在数组里面的字符串即可；

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        int n=digits.size();
        if(n==0) return result;
        vector<string>choose(10);
        choose[1]="";
        choose[2]="abc";
        choose[3]="def";
        choose[4]="ghi";
        choose[5]="jkl";
        choose[6]="mno";
        choose[7]="pqrs";
        choose[8]="tuv";
        choose[9]="wxyz";
        int num=0;
        int t=digits[num++]-'0';
        for(int i=0;i<choose[t].size();++i)
        {
            string temp="";
            temp+=choose[t][i];
            result.push_back(temp);
        }
        while(num<n){
            t=digits[num]-'0';
            int re_num=result.size(),ch_num=choose[t].size();
            for(int i=0;i<re_num;++i){      
                for(int j=0;j<ch_num-1;++j)
                result.push_back(result[i]+choose[t][j]);
            }
            for(int i=0;i<re_num;++i)
            result[i]+=choose[t][ch_num-1];
            ++num;
        }
        return result;
    }
};
```