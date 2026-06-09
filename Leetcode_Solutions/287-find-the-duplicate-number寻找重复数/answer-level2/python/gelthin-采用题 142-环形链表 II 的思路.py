### 解题思路
这题也是 1-n 的数字，但似乎无法用  nums[i]-1 作为下标的想法，题目[448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/gelthin-shi-yong-numsi-1zuo-wei-xia-biao-by-gelthi/) 却可以。

注释 ：
前面的两种方法不满足提示中给出的约束条件，但它们是您在技术面试中可能会想到的解决方案。作为一名面试官，我个人不希望有人提出循环解决方案。 采用思路 [142-环形链表II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

[liweiwei 提供了二分法的思路](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/)，初始区间 [1,n], 猜这个重复的数 x >= (1+n)//2, 那么就是说nums 数组中处于 [1, (1+n)//2-1] 区间内只有 (1+n)//2-1 个数，如果多于此，那么就需要往另一边缩小范围。

这样 T(n) = T(n/2) + O(n)   T(n) = nlogn


[陈牧远的评论](https://leetcode-cn.com/problems/find-the-duplicate-number/comments/33529)：
【笔记】这道题（据说）花费了计算机科学界的传奇人物Don Knuth 24小时才解出来。并且我只见过一个人（注：Keith Amling）用更短时间解出此题。

快慢指针，一个时间复杂度为O(N)的算法。

其一，对于链表问题，使用快慢指针可以判断是否有环。

其二，本题可以使用数组配合下标，抽象成链表问题。但是难点是要定位环的入口位置。

举个例子：nums = [2,5, 9 ,6,9,3,8, 9 ,7,1]，构造成链表就是：2->[9]->1->5->3->6->8->7->[9]，也就是在[9]处循环。

其三，快慢指针问题，会在环内的[9]->1->5->3->6->8->7->[9]任何一个节点追上，不一定是在[9]处相碰，事实上会在7处碰上。

其四，必须另起一个for循环定位环入口位置[9]。这里需要数学证明。

对“其四”简单说明一下，既然快慢指针在环内的某处已经相碰了。那么，第二个for循环遍历时，res指针还是在不停的绕环走，但是必定和i指针在环入口处相碰。
``` python3
int findDuplicate(vector<int>& nums) {
    int res = 0;
    for (int fast = 0; res != fast || fast == 0;){
        res = nums[res];
        fast = nums[nums[fast]];
    }
    cout << res;
    for (int i = 0; res != i; i = nums[i]){
        res = nums[res];
    }
    return res;
}
```


### 代码

```python3
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        a, b = nums[0], nums[0]
        while True:  # 这里错写成立 while a==b 导致初始化后没有运行
            a = nums[a]
            b = nums[nums[b]]
            if a == b:
                break
        c = nums[0]
        while b!=c:
            b = nums[b]
            c = nums[c]
        return c
```