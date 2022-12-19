### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string strlast=countAndSay(n-1);//当前节点=前一个节点的情况
        int count=1;
        string res;
        for(int i=0;i<strlast.size();i++){
            if(strlast[i]==strlast[i+1]){
                count++;
            }
            else{
                res+=to_string(count)+strlast[i];
                count=1;
            }
        }
        return res;
    }
};
```