从最后往回推,初始每步至少需要1,如果当前步数能力不满足就把需要步数加1并继续往回推//12到16ms.
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int a=1;//需要步数
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<a){
                a+=1;//把需要的步数"推卸"给前一步
            }
            else{
                a=1;//完成了需要的步数就初始化
            }
        }
    if(a==1)
        return 1;
    else
        return 0;
    }
};
```
