## 排序后，用k个指针来指向当前正确的(连续)k个数，然后每次尝试往后移，判断是否有不满足的。

```c++
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int len=nums.size();
        cout << len << endl;
        if(len%k){
            return false;
        }
        int vis[len+5]={0};
        sort(nums.begin(),nums.end());
        int tag[k+5]={-1};
        tag[0]=0;
        vis[tag[0]]=1;
        for(int i=1;i<k;i++){
            for(int j=tag[i-1]+1;j<len;j++){
                if(nums[j]==nums[tag[i-1]]+1){
                    tag[i]=j;
                    break;
                }
            }
            if(tag[i]==-1){
                return false;
            }
            vis[tag[i]]=1;
        }
        while(true){
            tag[0]++;
            while(vis[tag[0]] && tag[0]+1<len){
                tag[0]++;
            }
            if(vis[tag[0]]){
                break;
            }
            vis[tag[0]]=1;
            for(int i=1;i<k;i++){
                tag[i]=max(tag[i],tag[i-1])+1;
                while(tag[i]+1<len && (nums[tag[i]]!=nums[tag[i-1]]+1 || vis[tag[i]])){
                    tag[i]++;
                }
                if(nums[tag[i]]!=nums[tag[i-1]]+1 || vis[tag[i]]){
                    return false;
                }
                vis[tag[i]]=1;
            }
        }
        for(int i=0;i<len;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};
```
