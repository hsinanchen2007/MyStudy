双指针解法。 设置指针 begin=0,end=nums.size()-1。
仔细思考，这个题只需要一个从begin开始走，一个从end开始走，begin 的值为val 那么就与 end处不为val的交换，然后开始循环，循环结束条件begin>end; 当begin>end时候，那么begin前面的全不为val的值
在两边进行循环的时候，无非就四种情况。
    1、nums[begin]==val && nums[end]==val 这种情况，显然不能进行交换，只需要end-- 
    2、nums[begin]==val && nums[end]!=val 这种情况，nums[begin]=nums[end]即可，然后begin++,end--;
    3、nums[begin]!=val && nums[end]==val 这种情况，前边的数据不相等不需要交换，且end位置也为val不应该交换到前面去，所以 begin++ end--
    4、nums[begin]!=val && nums[end]!=val 这种请况，尾部符合条件，begin位置不是val所以不需要交换，只需要 begin++
![image.png](https://pic.leetcode-cn.com/a1c14a96fb3c5a07b52dd26d46d3fe8311c9867ee721903022a20e573f8b7330-image.png)

```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin=0,end=nums.size()-1;
        while(begin<=end){
            if(nums[begin]==val && nums[end]!=val){
                nums[begin]=nums[end];
                begin++;
                end--;
            }else if(nums[begin]!=val && nums[end]==val){
                begin++;
                end--;
            }else if(nums[begin]==val && nums[end]==val){
                end--;
            }else{
                begin++;
            }
        }
        return begin;
    }
};
```

