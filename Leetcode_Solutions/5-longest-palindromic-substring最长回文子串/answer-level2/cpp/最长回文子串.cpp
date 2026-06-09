### 解题思路
执行用时 :
68 ms
内存消耗 :
25 MB
为了排除回文子串长度的奇偶性，向原字串每个字符之间插入符号，最后按照奇数来查找，最后去符号得到最长回文子串。
### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
            if(s.empty()) return s;
    auto iter=s.begin();
    while(iter!=s.end()){
        iter=s.insert(iter,'*');//向原字串每个字符之间插入符号‘*’
        ++iter;
        ++iter;
    }
    s.insert(s.end(),'*');//向字串最后一个字符后插入符号
    
    string result;
    int n=s.size();
    int max_len=0;
    int tmp_len=0;
    int left_pos,right_pos;
    int shorter_len;
    int left_nums,right_nums;
    bool flag=false;//标志位，判断是否有回文字
    for(int i=1;i<n-1;++i){
        left_nums=i,right_nums=n-i-1;
        left_pos=right_pos=i;
        shorter_len=(left_nums<right_nums)?left_nums:right_nums;
        for(int k=1;k<=shorter_len;++k){
            if(s[i-k]==s[i+k]){
                flag=true;
                tmp_len=2*k+1;
                left_pos=i-k,right_pos=i+k;
                if(tmp_len>max_len){
                    max_len=tmp_len;
                    result=s.substr(left_pos,max_len);
                }
            }
            else break;
        }
    }
    //去符号
    auto pos=result.find("*");
    while(pos!=string::npos){
        result.erase(pos,1);
        pos=result.find("*");
    }
    if(flag)
        return result;
    else
        return result.substr(0,1);
    }
};
```