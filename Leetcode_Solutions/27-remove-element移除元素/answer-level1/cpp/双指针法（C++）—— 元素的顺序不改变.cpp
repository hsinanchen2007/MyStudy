大家可先尝试下第283题：移动零，与此题的解法类似。我采用的即是双指针法，既能完成题目要求，又能保证元素的顺序不改变。定义快慢指针，快指针fast用来遍历数组，当fast指向了非val的元素时，该元素和慢指针slow所在位置的元素交换，slow加一。遍历结束，slow的值即为非val的元素个数。
有人可能会问，这样就可以保证所有为val的元素就移动到数组的末尾了吗？
我们可以设val的元素个数是v，非val的元素个数是n。当v<=n时，经过交换，值为val的元素一定全被移至末尾；v>n时，非val的元素虽然不能全部发生交换（这里的交换不包括快慢指针指向同一处时的交换，毕竟自己和自己交换可以看作没发生交换），但由于数量较多，没发生交换的那些元素，实则已经在末尾了。举个例子，nums=[2,1,2],val=2。第一个2和1交换以后，变为[1,2,2]，其实第二个2并没有发生交换，但它已经在末尾了。
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=val){
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
                slow++;
            }
        }
        return slow;
    }
};
```
![1.png](https://pic.leetcode-cn.com/407f5c21f9bc9c2fb88c871680decfd496008eb4a8018668b9c53e82f1b53609-1.png)
