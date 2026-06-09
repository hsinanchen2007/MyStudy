# 题解来源
基本上将这里面的题解浏览了一遍，发现快慢指针这种解法很难想到，大部分同学想到的是将nums[num[i]] = -abs(nums[nums[i]])、排序、hash等。而快慢指针比较难理解，我看了@Damien_Undo的题解之后理解了这种解法，就有了这篇题解。
# 数组形式的链表
题目设定的问题是N+1个元素都在[1,n]这个范围内。这样我们可以用那个类似于 ‘缺失的第一个正数’ 这种解法来做，但是题意限制了我们不能修改原数组，我们只能另寻他法。也就是本编题解讲的方法，将这个**题目**给的**特殊的数组当作一个链表来看**，数组的下标就是指向元素的指针，把数组的元素也看作指针。如0是指针，**指向nums[0]，而nums[0]也是指针，指向nums[nums[0]]**.
这样我们就可以有这样的操作
```
int point = 0;
while(true){
    point = nums[point]; // 等同于 next = next->next; 
}
```
# 链表中的环
假设有这样一个样例：[1,2,3,4,5,6,7,8,9,5]。如果我们按照上面的循环下去就会得到这样一个路径: 1 2 3 4 5 [6 7 8 9] [6 7 8 9] [6 7 8 9] . . .这样就有了一个环，也就是6 7 8 9。point会一直在环中循环的前进。
这时我们设置两个一快(fast)一慢(slow)两个指针，一个每次走两步，一个每次走一步，这样让他们一直走下去，直到他们在重复的序列中相遇，
![image.png](https://pic.leetcode-cn.com/970cf34694dd893c64924e1559617f64ad6b5b272a81ac3de5836cb6fb42fed7-image.png)

```
int fast = 0, slow = 0;
while(true){
    fast = nums[nums[fast]];
    slow = nums[slow];
    if(fast == slow)
        break;
}
```

如上图，slow和fast会在环中相遇，**先假设一些量**：起点到环的入口长度为**m**，环的周长为**c**，在fast和slow相遇时slow走了**n**步。则fast走了2n步，fast比slow多走了n步，而这n步全用在了在环里循环（**n%c==0**）。
当fast和last相遇之后，我们设置第三个指针finder，它从起点开始和slow(在fast和slow相遇处)同步前进，当finder和slow相遇时，就是在环的入口处相遇，也就是重复的那个数字相遇。
# 为什么finder和slow相遇在入口
fast和slow相遇时，slow在环中行进的距离是n-m，其中n%c==0。这时我们再让slow前进m步——也就是在环中走了n步了。而n%c==0即slow在环里面走的距离是环的周长的整数倍，就回到了环的入口了，而入口就是重复的数字。
**我们不知道起点到入口的长度m，所以弄个finder和slow一起走，他们必定会在入口处相遇**。

# C++参考代码

```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int fast = 0, slow = 0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow)
                break;
        }
        int finder = 0;
        while(true){
            finder = nums[finder];
            slow = nums[slow];
            if(slow == finder)
                break;        
        }
        return slow;
    }
};
```
