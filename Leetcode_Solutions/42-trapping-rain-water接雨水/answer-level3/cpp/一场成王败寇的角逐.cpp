### 解题思路
这道题应该时困难题里面相对简单的（毕竟我这种蠢逼都可以写出来）
给定一个数组，每个数组对应的位置为该处的柱子高度，我们要求得这些柱子所围成得区域能接到得雨水得面积
- 要想接住雨水（盛住）起码需要两个高得板子和一个低得板子（例如：312）我们假设他们组成了一个木桶
    - 高的两块组成了边界，低得是桶底 
- 桶得宽度是两块板子得距离，桶得高度是边界板子最短得高度
- 一个桶里还可能装另外一个桶
那么我们要想解决这个问题就有以下几个关键要解决得问题
- 如何确定这是一个桶，能装雨水
- 一个桶装着另外一个桶得话那装得水怎么算
### 有趣得游戏-成王败寇
这是一个弱肉蚕食得时代，存在残酷得竞争，人人都想成为王者，大家不尊长幼，都想把前辈拍死在沙滩上
而衡量孰强孰弱得准则只有一个那就是谁长得高！！！！！！！！！
游戏规则如下：
- 打倒在自己之前所有比自己矮得人
- 打不过他就加入他成为他的护卫
    - 高个子的人要将自己的部分拨给他的护卫
我们可以设定一个栈用来存储所有现在在战斗着的士兵，每个来挑战的人根据自己打倒的士兵获得相应得奖励

### 数据结构
创建一个栈，用于存储现在得守卫者。
```cpp
struct info{
    int p; //所处得位置
    int h; // 护卫得高度
}
```
每一个数据进入得时候都没有护卫故其护卫得高度为0.

### 特判
柱子为空返回0，否则将第一个人入栈，他就是王者

### 核心
```cpp
if height[i] < height[st.top().p]{
    st.top.h = height[i]; //贴身护卫得高度
    st.push({i, 0};// 成为其护卫
} //打不过就加入
else{
    st.pop(); // 护卫挂掉了
    while(!st.empty() && height[i] >= height[st.top().p]) {
        res += ((min(height[i], height[st.top().p]) - st.top().h) * (i - st.top().p - 1)); // 短版-护卫得值 * 距离
        st.pop(); // 护卫挂了
    } // 当栈空时候，自己已经成为王者了，敌人全被打到了。或者碰到比自己强的护卫被干掉了
    if(!st.empty()) {
        res += ((min(height[i], height[st.top().p]) - st.top().h) * (i - st.top().p - 1));
        st.top().h = height[i]; // 成为比其高的人的护卫
    }// 如果是被护卫打死得，战死得奖励 
} // 打的过就消灭
```
### 写在后面
我也不知道大家会不会看到能不能看懂，反正就那么回事吧。哈哈哈哈哈哈

### 代码

4ms

```cpp
class Solution {
struct info{
    int p; // 位置
    int h; // 高度
};
public:
    int trap(vector<int>& height){
        // 找到并消灭高个子的人
        // 栈:高等于出栈，低等于减去该值
        int res = 0;
        stack<info> st;
        if(height.size() == 0) return 0;
        st.push({0,0});
        for(int i=1; i<height.size(); ++i){
            if(height[i] < height[st.top().p]){
                st.top().h = height[i]; //记录贴身护卫的高度
                st.push({i,0}); // 成为高个子的人的护卫
            } // 当前元素比能看见的敌人个子矮
            else{
                st.pop(); //
                // 
                while(!st.empty() && height[i] >= height[st.top().p]) {
                    res += ((min(height[i], height[st.top().p]) - st.top().h) * (i - st.top().p - 1)); // 获取矩阵值
                    st.pop();
                }
                if(!st.empty()) {
                    res += ((min(height[i], height[st.top().p]) - st.top().h) * (i - st.top().p - 1));
                    st.top().h = height[i]; // 成为比其高的人的护卫
                }
                st.push({i, 0});
            }   
        } // 比看见的敌人个子高
        return res;
    }
};
```