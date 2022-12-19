### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findString(vector<string>& words, string s) {
        int l=0,r=words.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(words[mid]==""){
                if(words[r]==s){
                    return r;
                }
                r--;
                continue;
            }
            else if(words[mid]==s){
                return mid;
            }
            else if(words[mid]<s){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};
```