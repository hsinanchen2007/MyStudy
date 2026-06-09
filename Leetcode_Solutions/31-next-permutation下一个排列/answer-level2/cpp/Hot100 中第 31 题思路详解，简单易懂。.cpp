### 解题思路
第一步：首先分析特殊情况，如果数组为空或者只有一个数，就没有处理的必要直接退出即可
第二步：如果传入的数组长度大于1，就开始从右往左遍历，找到破坏（从右往左）升序的数组下标pos_swap-1。
此时会有两种情况。
1. 第一种情况：该数组（从右往左）自始至终都是升序，即pos_swap=0，那么反转一下即可。例如：3 2 1 反转后 1 2 3
2. 第二种情况：如果pos_swap>0,只看此时pos_swap到end处的值必定是最大值。举个列子帮助理解，例如原始排列是4 3 0 2 4 3 2 0，通过上面步骤的处理，pos_swap到end处的值是4 3 2 0，而 pos_swap-1 处的值是 2。显然 0 到 pos_swap-1 处的值4 3 0不用再处理了，因为 2 与 4 3 2 0里比2大的数交换就可以比原始排列大了，因此只处理 2 4 3 2 0就行了。到这里一定要理解为什么只处理 2 4 3 2 0。
3. 理解上面的再继续处理第二种情况：先将pos_swap到end处的值反转成（从左往右）升序，此时 4 3 2 0 变成了 0 2 3 4。然后 2 这个值要和 0 2 3 4里面比2大的值交换才能比原始排列大。那么就开始第二遍遍历吧。拿2分别和 0 2 3 4比较。发现 2 比 0 2 3 4中的3大，交换它们变成3 0 2 2 4。最终结果也就是4 2 0 3 0 2 2 4。


### 运行结果：
![image.png](https://pic.leetcode-cn.com/c1b503ca3c672a5fc9988e9425af27b8b67dfb90fa8b9274935104f22e42256b-image.png)

### 代码
```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //如果没有数 或者只有一个数 就不用了处理
        if(nums.empty() || nums.size() == 1)
            return;
        int pos_swap = nums.size()-1;
        //从右往左遍历一遍 找到破坏升序的那个位置 这个位置就是待交换的地方 
        while(pos_swap > 0) //遍历1到end
        {
            //如果一直是升序 位置下标左移
            if(nums[pos_swap] <= nums[pos_swap-1])
                pos_swap--;
            else//如果找到破坏升序的位置pos_swap-1  就是待交换的地方 
                break; //退出循环
        }
        //pos_swap == 0证明该数组从左往右是降序排列的 此时反转一下即可
        if(pos_swap == 0)
        {
            reverse(nums.begin(), nums.end());
        }//否则 肯定存在比此时更大的下一个排列
        else{
            //先将pos_swap到end处反转成从左到右升序 方便找到另一个交换的值
            reverse(nums.begin()+pos_swap, nums.end());
//开始从左往右找比pos_swap-1大的数 且一定是与pos_swap最相近的数 因为找的地方是从左到右升序排列的
            for(int i = pos_swap; i < nums.size(); i++)
            {
                //如果i处的数大于待交换位置的数
                if(nums[i] > nums[pos_swap-1])
                {
                    swap(nums[i], nums[pos_swap-1]); //交换两个数
                    return; //跳出函数即可
                }
            }
        }
        


    }
};
```