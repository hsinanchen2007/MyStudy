### 解题思路
此处撰写解题思路
这道题有很多坑。做法如下：
首先，我们需要让每一个单词变成：单词+' ' 这样的形式，使用vector存储；
其次，然后将vector中的元素串起来，变成一个字符串；
然后，就是先将每一个单词+' ' 进行反转；
最后将整个字符串进行反转，就得到了结果。 
### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(s.size()==0) return "";

        s+=' ';
        vector<string> vec;
        string temp;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else{
                if(temp.size()){
                    temp=temp+' ';
                    vec.push_back(temp);
                }
                temp.clear();
            }
        }

        string ans="";
        for(int i=0;i<vec.size();i++){
            ans+=vec[i];
        } 

        int left=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==' '){
                int right=i;
                for(;left<right;left++,right--) swap(ans[left],ans[right]);
                i++;
                left=i;
            }
        }

        for(int i=0,j=ans.size()-1;i<j;i++,j--) swap(ans[i],ans[j]);
        ans=ans.substr(0,ans.size()-1);
        return ans;
    }
};
```