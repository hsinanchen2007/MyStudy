### 解题思路
此处撰写解题思路

### 代码

```cpp

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int ans=0,taken=0;
        int cnt[80001]={0};
        for(int i=0;i<A.size();i++) cnt[A[i]]++;
        for(int i=0;i<80001;i++){
            if(cnt[i]>1){
                taken+=cnt[i]-1;
                ans-=i*(cnt[i]-1);
            }
            else if(taken>0 && cnt[i]==0){
                ans+=i;
                taken--;
            }
        }
        return ans;
    }
};


```