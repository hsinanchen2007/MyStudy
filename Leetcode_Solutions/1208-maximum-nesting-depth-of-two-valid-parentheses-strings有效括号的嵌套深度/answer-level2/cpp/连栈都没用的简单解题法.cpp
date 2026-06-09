大家应该都发现了，只要按照奇偶分配就可以得到结果。
我虽然没用栈，但是也需要算括号的深度。
时间复杂度O(n)
```
class Solution {
public:
    int nums[10010]={0};
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        int temp0=0,temp1=0;
        for(int i=0;i<n;++i){
            if(seq[i]=='('){temp1=temp0+1;temp0++;}
            else {temp0--;temp1=temp0+1;}
            nums[i]=temp1;
        }
        vector<int>ans;
        for(int i=0;i<n;++i){
            if(nums[i]%2==1)ans.push_back(0);
            else ans.push_back(1);
        }
        return ans;
    }
};
```
