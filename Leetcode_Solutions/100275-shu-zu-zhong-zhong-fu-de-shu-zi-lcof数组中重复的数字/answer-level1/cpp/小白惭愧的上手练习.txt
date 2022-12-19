### 备注
太久没做题了，手感相当生疏，连set等一些基本集合的使用方法都给忘了，只能期待在练习中进步吧。

### 解题思路
相当赞同大佬们关于这题考察侧重点的观点，这道题本身不难，可出发的角度有很多，但是考察的重点是提问者的真实需求，时间和空间是相互制衡的，如果追求时间则可用额外的空间换时间（如哈希法，集合等），如果追求空间则可用额外的时间换空间（如先排序，则遍历查重，但在问题输入规模较大时不太现实）。
本题我仅采用简单的哈希法来换个通过，并在此题解中记录遇到的丢人问题。
以此谨记：做题一是审清题想好思路再动手，二是做题中思路要清晰，不要想着靠反馈来检验对错。
### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        bool buck[nums.size()];//范围是0~n-1，则大小为nums.size()，注意数组的起始位为0
        memset(buck, false, nums.size());
        for(int i =0;i<nums.size();i++){
            if(buck[nums[i]]){
               return nums[i];//注意返回值到底是buck[]还是nums[i]
            }else 
                buck[nums[i]] = true;
        }
        return 0;
    }
};
```