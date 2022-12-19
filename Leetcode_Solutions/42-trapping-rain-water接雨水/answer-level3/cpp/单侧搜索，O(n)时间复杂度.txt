执行用时：8 ms
内存消耗：6.6 MB
比官方给的第三种方法略慢，时间超过大多数的68%
这个题主要就是**从左侧开始搜索**，当遇到数组中的一部分**不满足右侧一定会出现比左侧大的值时**（即[4,2,3]），将该部分**转为从右侧开始搜索**。
从左侧开始依次搜索，将当前位置的值记为height[left],向右搜索，如果比height[left]的值小，将二者差值统计起来，直到找到比height[left]大的值，然后将之前统计的差值的和加到结果中。
如果直到搜索到数组最右侧，也没有找到比height[left]大的值，则之前统计的差值作废，可能是出现[4,2,3]这样的情况，因此将数组left位置处开始的序列，转为从右侧开始搜索。
```
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int ans=0;
        while(left<height.size()){
            int i=left+1;
            int sum=0;
            while(i<height.size()&&height[i]<height[left]){//比最左侧height[left]小的都统计进来
                sum+=height[left]-height[i];
                i++;
            }
            if(i!=height.size()){//如果在搜索过程中遇到比height[left]大的值，就把之前累加的结果计算进来
                ans+=sum;
                left=i;
            }
            else{//如果没有搜索到比height[left]大的值，即类似[4,2,3]类型的序列，转为从右侧开始搜索，方法同左侧
                int right=height.size()-1;
                while(right>=left){
                    int j=right-1;
                    int tmp=0;
                    while(j>=left&&height[j]<height[right]){
                        tmp+=height[right]-height[j];

                        j--;
                    }
                    if(j!=left-1){
                        ans+=tmp;
                        right=j;
                    }
                    else right--;
                }
                left=height.size();
            }
        }
        return ans;
    }
};
```
