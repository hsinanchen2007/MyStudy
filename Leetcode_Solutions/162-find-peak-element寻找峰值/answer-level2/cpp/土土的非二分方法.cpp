### 解题思路
emmm，搞一个非2分的土办法，可以取三个指针，分别对前一个数字，中间数字，后面的数字，峰值节点无非就是存在一个节点，其节点的前后元素的值都比当前节点的值小；那么从节点的头开始遍历，寻找到这样的节点存一哈就好了。
emmm，需要注意下特殊情况，比如这个数组是一开始就是一个递减序列，那么第一个元素就是峰值；或者遍历到最后发现是个递增序列，最后一个元素就是峰值。
最后说句，FGNB，RUA！
（emmm圈复杂度超了....)
### 代码

```cpp
class Solution {
public:
   int  findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }else if (nums.size()==2){
            if( nums[1]> nums[0]){
                return 1;
            }else{
                return 0;
            }
        }
        int numsLength = nums.size();
        vector <int> topNode;
        for (int i =2; i < numsLength; ++i){
            int first = nums[i-2];
            int middle = nums[i-1];
            int last  = nums[i] ;
            if(middle>last && middle > first){
                topNode.push_back(i-1);
            }else if( i == numsLength-1 && last>middle){
                topNode.push_back(i);
            }else if(i-2 == 0 && first > middle){
                topNode.push_back(i-2);
            }
        }

        return topNode[0];
    }
};
```