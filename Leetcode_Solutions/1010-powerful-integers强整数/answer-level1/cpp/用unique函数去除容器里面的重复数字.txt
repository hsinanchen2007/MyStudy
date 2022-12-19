### 解题思路
c++ 双100

1.分别计算出bound是x和y的几次幂
2.使用for循环，向容器添加符合的数字
3.排序，去除容器中重复的数字
**考虑x或者y等于1特殊情况**

### 代码

```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        int a=0,b=0;
        vector<int> vec;
        if(x==1)
            a=1;
        if(y==1)
            b=1;
        while(x!=1&&pow(x,a)<bound)
        {
            a++;
        }
        while(y!=1&&pow(y,b)<bound)
        {
            b++;
        }
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
            {
                int m=pow(x,i)+pow(y,j);
                if(m<=bound)
                    vec.push_back(m);
            }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        return vec;
    }
};
```