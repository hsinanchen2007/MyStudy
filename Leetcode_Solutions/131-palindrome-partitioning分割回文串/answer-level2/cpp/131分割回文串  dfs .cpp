### 解题思路
返回 s 所有可能的分割方案。想到用dfs
以每次有多种选择，选择其中一种再dfs进行下一层的字符串的划分
     所以，下一层的字符串要更新，所以每次切割都是从0开始切割
每次的选择，是以切多长来进行的，所以for(int i=1;i<=s.size();i++)i代表切割的长度

如果这个选择不是回文串就不操作，而continue下一个i长度的选择



### 代码

```cpp
class Solution {
public:
    bool check(string s){
        if(s.size()==1)
            return true;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
            }
            return true;
        }
        
 void dfs(string s,vector<vector<string>>&res,vector<string> temp){
     if(s=="") {
         res.push_back(temp);
         return;
     }
     for(int i=1;i<=s.size();i++){//i是每次选择划分多长
         string sub=s.substr(0,i);//每次都是从0开始划分，因为s更新的
         if(check(sub)) {//如果不是回文，那么就要重新进入下一个长度的选择，不进行其他操作
         temp.push_back(sub);
         dfs(s.substr(i,s.size()-i),res,temp);//每次切掉之后要更新s
         //切掉前面的，用新的s进行划分，所以每次s.substr(0,i);都是从0开始划分
         temp.pop_back();//本次选了它，要重新选择就要抛掉，不管&与否
         }
           
     }
 }

    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>res;
        dfs(s,res,temp);
        return res;
    }
};
```