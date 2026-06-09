```
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int a[100005];
        for(int i=0;i<100005;i++){
            a[i]=0;
        }
        int ans;
        vector<int>::iterator it;
        for(it=nums.begin();it!=nums.end();++it){
            a[*it]++;
        }
        for(int i=0;i<100005;i++){
            if(a[i]>1){//a[i]不为1,说明数字i不只出现1次
                ans=i;
                break;
            }
        }
        return ans;
    }
};
```
