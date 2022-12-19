### 解题思路
时间：0ms 100%
空间就有点惨不忍睹，8.3MB 一半多一点
思路：我们使用光的反射定律的一点思想，看一下每当广打在左右墙壁上时y轴方向位置
考虑两种特殊情况：
1.超出上界
![反射问题图解1.png](https://pic.leetcode-cn.com/30368a52d69694549b207ecac04329bdd028372048b0d5a6685377e3bdd6581d-%E5%8F%8D%E5%B0%84%E9%97%AE%E9%A2%98%E5%9B%BE%E8%A7%A31.png)
如图，此时，我们可以根据光的反射定律得出，经过这次反射y方向坐标yn+1 = p-((yn-1+q)%p)即p减去多余
2.而对于超出下界......
![反射问题图解2.png](https://pic.leetcode-cn.com/90df376178601a5b0f2d0afd7b772c171ca30ee72ed6caced0607fa91cfa6b65-%E5%8F%8D%E5%B0%84%E9%97%AE%E9%A2%98%E5%9B%BE%E8%A7%A32.png)
对了，就等于超出部分
**注意，每次超出上下界......或者说碰到上下墙壁，y方向光线方向变反**
一直反射下去，知道到达探测器

### 代码

```cpp
class Solution {
public:
    int mirrorReflection(int p, int q) {
        vector<int> position = {0,0};
        vector<vector<int>> catchers = {{p,0},{p,p},{0,p}}; //探测器坐标
        int directx = 1,directy = 1;//方向向量
        while(true) {
            position[0] += directx*p;
            directx *= -1;//每次反射，光线X轴方向变反
            position[1] += directy*q;
            if(position[1] > p) {
                position[1] = p-(position[1]%p); //超上界处理
                directy *= -1; //注意方向，变反
            }
            if(position[1] < 0) {
                position[1] = -position[1];
                directy *= -1; //方向
            } 
            for(int i=0;i<catchers.size();++i)
                if(position == catchers[i]) return i; //检测是否到达探测器
        }
        return false;
    }
};
```