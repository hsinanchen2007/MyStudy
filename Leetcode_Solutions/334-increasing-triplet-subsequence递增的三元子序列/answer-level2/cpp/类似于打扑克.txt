生活经验告诉我们，一个较小的数后面更容易接大数，就像我们打扑克总是小牌插到大牌前边。
不同的是我们只需要维护大小为2的数组`cat`即可。每次只需要比较当前元素和`cat[0]`和`cat[1]`的大小，如果比`cat[0]`小，则替换`cat[0]`;同理比`cat[1]`小，则替换`cat[1]`，但是一旦当前元素比`cat[1]`大，那说明我们找到了一个升序三元组，直接`return`就可以了。
```
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<=2)return false;
        int* catgary=new int[2]{INT_MAX,INT_MAX};//注意初始化，一定是两个INT_MAX
        for(int count=0;count<nums.size();count++){
            if(nums[count]<=catgary[0]){
                catgary[0]=nums[count];
            }else if(nums[count]<=catgary[1]){
                catgary[1]=nums[count];
            }else{
                return true;
            }
        }
        return false;
    }
};
```
