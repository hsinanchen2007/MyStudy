### 解题思路
对比大佬的解答[快慢指针的解释 [从@Damien_Undo写的题解得到启发](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/kuai-man-zhi-zhen-de-jie-shi-cong-damien_undoxie-d/)

这种方式应该注意的细节是乌龟和兔子需要初始化：
    int turtle=nums[0];
    int rabbit=nums[nums[0]];
不然无法执行:
    while(turtle!=rabbit)

注意一个比较关键的观点：nums数组下标和对应的值的意义不再是本来的意思（即下标和对应的值），***而是nums[i]->i这样的链表关系**，也就是说不论是nums[i]还是它的下标i都是**节点**了*。于是采用我写得代码的初始化就都应该是第一个节点0(龟兔起跑线)。
参考题解：
[快慢指针的解释 [从@Damien_Undo写的题解得到启发]](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/kuai-man-zhi-zhen-de-jie-shi-cong-damien_undoxie-d/)
[寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode/)
[快慢指针的解释 [从@Damien_Undo写的题解得到启发]](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/kuai-man-zhi-zhen-de-jie-shi-cong-damien_undoxie-d/)



BTW,官方解答[寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode/)中使用的tortoise是陆龟，而我使用的turtle是海归；hare是尤指野兔，rabbit大概是普通兔子。看来还是官方的选词更字节。
### 代码

```c
int findDuplicate(int* nums, int numsSize){
    int turtle=nums[0];
    int rabbit=nums[nums[0]];
    int find=0;
    while(turtle!=rabbit){
        turtle=nums[turtle];
        rabbit=nums[nums[rabbit]];
    }
    while(find!=turtle){
        find=nums[find];
        turtle=nums[turtle];
    }
    return find;
}
```
收到一些启发， 使用这种while循环的技巧似乎更加利于思考。

```c
int findDuplicate(int* nums, int numsSize){
    //初始化起跑线，第一个节点
    int turtle=0;
    int rabbit=0;
    int find=0;
    while(true){
        turtle=nums[turtle];
        rabbit=nums[nums[rabbit]];
        if(turtle==rabbit) break;
    }
    while(true){
        find=nums[find];
        turtle=nums[turtle];
        if(find==turtle) return find;
    }
}
```
