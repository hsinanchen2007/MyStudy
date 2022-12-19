### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size()==0){
            return 0;
        }

        int maxnum=citations[0];
        int minnum=citations[0];

        for(int i=0;i<citations.size();i++){
            maxnum=max(maxnum,citations[i]);
            minnum=min(minnum,citations[i]);
        }

        int range=maxnum-minnum+1;
        vector<int> ans(range,0);
        for(int i=0;i<citations.size();i++){
            ans[citations[i]-minnum]++;
        }

        int j=0;
        for(int i=range-1;i>=0;i--){
            while(ans[i]!=0){
                citations[j]=i+minnum;
                j++;
                ans[i]--;
            }
        }
        
        int count=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]>count){
                count++;
            }
            else{
                break;
            }
        }
        return count;

    }
};
```