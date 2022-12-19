### 解题思路
也是和标答思路大致一样，不过标答细节有个地方没提（cur与左侧交换时不增加），然后发现写的通不过，感觉很坑。
1.核心思路：
通过cur指针将数组进行遍历，将cur所遍历过的数中的0与2分别移动到数组左侧与右侧：
(1) p0表示0最右侧的指针，p2表示2最左侧的指针
(2)如果nums[cur]==0,将nums[p0]与nums[cur]交换，实际上就是将p0位置上的0或1换到cur,p0与cur右移
(3)如果nums[cur]==2,将nums[p2]与nums[cur]交换,p2左移而cur不发生移动，因为cur这个位置的数没有遍历过；
(4)如果nums[cur]==1, cur右移,继续遍历；
实际上，当cur与p2指针相遇时，已经遍历完成，因为p2之后的数在(3)步中已经遍历过了

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur=0,p0=0,p2=nums.size()-1;
       while(cur<=p2){
            if(nums[cur]==0) { nums[cur++]=nums[p0]; nums[p0++]=0; }
            else if(nums[cur]==2) { nums[cur]=nums[p2]; nums[p2--]=2; }
            else cur++;
        }
    }
};
```