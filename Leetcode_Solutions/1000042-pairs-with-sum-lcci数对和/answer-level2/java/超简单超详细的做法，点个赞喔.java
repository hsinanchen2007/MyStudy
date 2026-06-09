## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)



## 题目讲解

**【核心思想】**
* 双指针一个从前往后，一个从后往前

**【数据结构】**
* 数组

**【思路】**
1. 排序
2. 使用两个指针`start`和`end`指向数组的头部和尾部
3. 若`nums[start] + nums[end] < target`，则`start++`
4. 若`nums[start] + nums[end] > target`，则`end--`
5. 若`nums[start] + nums[end] == target`，则符合条件，加入`list`



**【代码】**
```java
public List<List<Integer>> pairSums(int[] nums, int target) {
    Arrays.sort(nums);
    int start=0,end=nums.length-1;
    List<List<Integer>> ans=new ArrayList<>();
    while(start<end){
        if(nums[start]+nums[end]==target){
            List<Integer> list=new ArrayList<>();
            list.add(nums[start]);
            list.add(nums[end]);
            ans.add(list);
            start++;
            end--;
        }
        else if(nums[start]+nums[end]<target)
            start++;
        else
            end--;
    }
    return ans;
}
```
**【关注微信公众号，带你拿大厂offer】**

![logo_gif.gif](https://pic.leetcode-cn.com/f6d7085de4095860835e77030f7fd659dc589c02e9fbc0ed5e125ca913d1b15f-logo_gif.gif)