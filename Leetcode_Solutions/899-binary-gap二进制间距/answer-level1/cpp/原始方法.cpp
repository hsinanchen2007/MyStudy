### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int binaryGap(int N) {
        vector<int> ans;
        while(N){
            ans.push_back(N%2);
            N/=2;
        }
        int i=-1,j=-1,max1=0;
        for(int k=0;k<ans.size();k++){
            if(ans[k]==1){
                i=j;
                j=k;
                if(i!=-1){
                    max1=max(max1,j-i);
                }
            }
        }
        return max1;
    }
};
```