### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int i=-1,j=0;
        int n=S.length();
        vector<int> ans;
        while(j<=n){
            while(j<n&&S[j]!=C){
                j++;
            }
            if(i==-1){
                for(i=0;i<j;i++){
                    ans.push_back(j-i);
                }
            }
            else{
                if(j>=n){
                     for(int k=i;k<j;k++){
                        ans.push_back(k-i);
                    }
                }
                else
                    for(int k=i;k<j;k++){
                        ans.push_back(min(j-k,k-i));
                    }
            }
            i=j;
            j++;
        }
        return ans;
    }
};
```