### 解题思路
1.去掉s左右的空格
2.逆序s
3.从头遍历找到单词,对每一个单词逆序加入到结果中
4.去掉多余的空格

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        while(i<n&&s[i]==' ')
            i++;
        int j=n-1;
        while(j>=0&&s[j]==' ')
            j--;
        //去掉多余的空格
        s=s.substr(i,j+1-i);
        //整体逆序
        reverse(s.begin(),s.end());
        i=0;
        n=s.size();
        string ans;
        while(i<n){
            j=i;
            while(j<n&&s[j]!=' ')
                j++;
            reverse(s.begin()+i,s.begin()+j);
            //找到单词加入到结果中
            ans+=s.substr(i,j-i);
            if(j<n)
                ans+=" ";
            //跳过多余的空格
            while(j<n&&s[j]==' ')
                j++;
            i=j;
        }
        return ans;
    }
};
```