


```
class Solution287 {
    public int findDuplicate(int[] nums) {
        int fast=0;int slow=0;//定义快慢指针
        while (true){
            fast=nums[nums[fast]];//快指针速度为2
            slow=nums[slow];//慢指针速度为1
            if(fast==slow){ //环形跑道直至相遇
                fast=0;//让快指针回到起点
                while (fast!=slow) {
                    fast = nums[fast];//快指针速度减为1
                    slow = nums[slow];//慢指针速度不变
                }
                return fast;//第二次相遇 即为环形跑道的入口  也即为这道题的答案  下面有详细证明
            }
        }
    }
}
```
![图解.jpg](https://pic.leetcode-cn.com/42fa3f0c45466c47e9a26d5d5f9d2e5f76607edb8f7deace6112ae09803f8712-%E5%9B%BE%E8%A7%A3.jpg)
