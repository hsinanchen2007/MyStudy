### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:               //思路是一样的，可是解题方面，换位思考不如别人
    bool isPossibleDivide(vector<int>& nums, int k) {
        int len= nums.size();
        if(len%k!=0||len<k) return false;
        int j=0,count=0,tmp;
        sort(nums.begin(),nums.end());//这里需要排序，否则如果i为最大的，找不到比他大的，就会报错，实际上他和前面的使用了
        map<int,int>res;//注意这里不能使用数组vector（它是连续存储） 1.元素的最大值不确定，可能会超过内存 2.用vector不如使用map(不是连续存储)
        for(int i=0;i<len;i++){
            res[nums[i]]++;
        }
        int maxsize=len/k,countsize=0;
        for(int i=0;i<len;i++){   //我之前的想法是：i存在，然后和j（j是i的上一个位置，等到了k个元素之后，i重新从0开始）判断ij是否为同一个元素，相同的话，i向后走，j等于当前的i。这种方法实在太蠢，复杂度为n2，而且造成下标有问题。
            j=i;  //作为位置的辅助变量
            tmp=nums[j];
            if(res[tmp]==0) continue;
            while(count<k){
                if(res[tmp]) {
                    cout<<res[tmp]<<endl;
                    res[tmp]--;
                    tmp++;
                    count++;
                }
                else return false;
            }

            count=0;
            countsize++;
            if(countsize==maxsize) return true;
        }
        return true;
    }
};
```