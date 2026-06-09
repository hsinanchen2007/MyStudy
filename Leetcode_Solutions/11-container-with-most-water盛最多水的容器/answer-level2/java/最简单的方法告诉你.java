## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)


**【核心思想】**
* 双指针，一个从前向后遍历，一个从后向前遍历


**【思路】**
* 设置两个指针，一个放在数组开始，一个放在数组末尾
* 每一次计算当前两个指针围城的面积
* 将指向较短线段的指针向较长线段那端移动一步


**【代码】**
```java
public int maxArea(int[] height) {
    int start=0,end=height.length-1;
    int ans=0;
    while(start<end){
        ans=Math.max(ans,Math.min(height[start],height[end])*(end-start));
        if(height[start]>height[end])
            end--;
        else
            start++;
    }
    return ans;

}
```