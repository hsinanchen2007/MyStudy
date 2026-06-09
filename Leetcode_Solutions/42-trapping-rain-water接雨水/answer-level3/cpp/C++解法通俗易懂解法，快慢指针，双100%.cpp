# 思考：
题意要求的是，往这几堵墙组成的区域中灌水，求出该区域总共能够存储多少水；
拿到这个题目，我想到了多种解法：
# 方法一：像素点解法
    我们不妨将整个区域看成由无数个 长宽都为1 的正方形组成，也就是一个个“像素点”；
    然后定义坐标系：X=数组元素下标；Y=数组元素大小；
    那么很容易地，我们能得出该区域每一个“像素点”；
    接着我们对X轴(数组元素下标)进行遍历，将X轴中所有为墙体的“像素点”的Y坐标都放入一个map容器；
    通过上面的遍历，我们就能从map容器中得出 整个坐标系所有的墙体坐标；
那么可装水的总量就是：

```
res += map_final[i] - map_first[i] - map_count[i] + 1 (i = 最高墙体的Y坐标)
```
其中 map_first记录Y=i时该高度第一次出现墙体的位置；map_final记录该高度最后一次出现位置；map_count记录Y=i时该高度上墙体数量

代码如下：
```
class Solution {
public:
    int trap(vector<int>& height) {
        unordered_map<int, int> m_first, m_final, map_first, map_final;
        int res = 0;
        for(int i = 0; i < height.size(); i++){
            for(int max_h = height[i]; max_h >= 0; max_h--){
                m_first[max_h]++;
                if(m_first[max_h] == 1){
                    map_first[max_h] = i;
                }
            }
        }
        for(int i = height.size()-1; i >= 0; i--){
            for(int max_h = height[i]; max_h >= 0; max_h--){
                m_final[max_h]++;
                if(m_final[max_h] == 1){
                    map_final[max_h] = i;
                }
            }
        }
        for(int i = 0; i < m_first.size(); i++){
            res += (map_final[i] - map_first[i]) - m_first[i] + 1;
        }
        return res;
    }
};
```

然鹅实际情况却是，314/315个通过测试用例，没错，最后一个超时了，显然for循环嵌套太多，时间复杂度太高了。

# 方法二：快慢指针法
    快慢指针大法好，而且代码非常易懂；
    我们的代码只需实现三步：
        1、找到墙体中的最高点(也就是数组元素最大值，这个最大值要尽量靠右，也就是相等取最右)
        2、以最高点为中心，对左半边“装水”
        3、以最高点为中心，对右半边“装水”
    最后 return 这两边水数量的和就好啦~

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = i+1, res = 0, res_mem = 0, max_h = 0;
        // 找到最高点 max_h
        for(int v = 0; v < height.size(); v++){
            max_h = height[v] >= height[max_h] ? v : max_h;
        }
        // 对左半边灌水~也就是找出左半边能装多少水
        while(i <= max_h && j <= max_h){
            if(height[j] < height[i]){
                res += (height[i] - height[j++]);
            }
            else{
                i = j++;
            }
        }
        // 对右半边灌水~也就是找出右半边能装多少水
        i = height.size()-1, j = i-1;
        while(i >= max_h && j >= max_h){
            if(height[j] < height[i])
                // 右半边的水不能一次性加入res，需要缓存！
                // 因为诸如 311411 这种，最右边有可能会漏水~
                // 诸如 311412这种，就不会漏水~
                res_mem += (height[i] - height[j--]);
            else{
                i = j--;
                res += res_mem;
                res_mem = 0;
            }
        }
        return res;
    }
};
```

这个解法可达到双100%的速度~