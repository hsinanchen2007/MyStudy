### 解题思路
接雨水即找容器。
容器的特點為：兩邊高四周低。
邊的特點為：兩邊都小於邊的值（因爲容器時凹的），在數組中表現為極值，特點為大於左右兩邊的值
使用Left存貯左邊，right存儲右邊，每次的right都會成爲下一次循環的左邊，除非找不到另外的右邊。儅找不到右邊時循環停止因爲沒有容器了。
要注意的是，右邊的特點不光是極值，還有可能是最值。例如[4,2,3,2,6]中，3是極值，但是6才是正確的右邊。
            而在[4,2,5,2,8]中，4為左邊時5才是右邊
因此右邊應滿足的條件爲：小於等於left的最大值或者大於left的極值
### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height){
        int left=0,h=0,right=0,n=height.size();
        long long ans=0;//一定要初始化
        bool hasRight=false,hasLeft=false;
    for(int i=0;i<n;i++){
        if(!hasLeft){
            left=0;
            if(height[i]>0) 
            {    
                for(int j=i+1;j<n;j++)
                    if(height[j]>=height[j-1]&&((j<n-1&&height[j]>=height[j+1])||j==n-1)){
                    left=height[i];
                    hasRight=true;
                    right=max(right,height[j]);
                    h=min(right,left);
                    }
                if(hasRight){
                    hasLeft=true;
                    left=height[i];
                } 
            }
        }else if(hasLeft)
        {     
            if(height[i]>=h) 
            {
                left=height[i];//更新left
                hasRight=false;
                right=0;
                 for(int j=i+1;j<n;j++){ //right更新
                    if(height[j]>=height[j-1]&&((j<n-1&&height[j]>=height[j+1])||j==n-1)){
                    hasRight=true;
                    right=max(right,height[j]);
                    h=min(right,left);//min(right,left);
                    }
                 }
                    if(!hasRight) break;//沒有剩下的了
            }else ans+=h-height[i];
        } 
              }
    return ans;
    }
};
```