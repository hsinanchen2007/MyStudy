思路比较简单需要特判一下第一行和最后一行，第一行和最后一行都是i+count,中间的先加count,再加temp-count一直加到大于等于原数组。找到规律就很简单了
```c++
class Solution {
public:
    string convert(string s, int numRows) {
        string ans=s;
        int i=0,j=0,k=0,count=(numRows-1)*2,temp=count;
        if(numRows==1)return s;
        for(i = 0;i<numRows;i++){
            ans[k++] = s[i];
            for(j=0;k<s.length()&&i+j<s.length();){
                if(i==0||i==numRows-1){
                    j+=temp;
                    if(i+j<s.length())
                    ans[k++]= s[i+j];
                }
                else{
                    j += count;
                    if(i+j<s.length())
                    ans[k++] = s[i+j];
                    j += temp - count;
                    if(i+j<s.length())
                    ans[k++] = s[i+j];
                }
            }
            count-=2;
        }
        return ans;
    }
};
```思路比较简单需要特判一下第一行和最后一行，第一行和最后一行都是i+count,中间的先加count,再加temp-count一直加到大于等于原数组。找到规律就很简单了
```c++
class Solution {
public:
    string convert(string s, int numRows) {
        string ans=s;
        int i=0,j=0,k=0,count=(numRows-1)*2,temp=count;
        if(numRows==1)return s;
        for(i = 0;i<numRows;i++){
            ans[k++] = s[i];
            for(j=0;k<s.length()&&i+j<s.length();){
                if(i==0||i==numRows-1){
                    j+=temp;
                    if(i+j<s.length())
                    ans[k++]= s[i+j];
                }
                else{
                    j += count;
                    if(i+j<s.length())
                    ans[k++] = s[i+j];
                    j += temp - count;
                    if(i+j<s.length())
                    ans[k++] = s[i+j];
                }
            }
            count-=2;
        }
        return ans;
    }
};
```