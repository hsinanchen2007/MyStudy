### 解题思路
![25844004-5A59-4f9c-81E1-86904A04D7B6.png](https://pic.leetcode-cn.com/bfb4fec0a221a9f44067a5dea3751b438bffb447e936785049720cf16ac9defc-25844004-5A59-4f9c-81E1-86904A04D7B6.png)
具体可以看这个视频[https://www.bilibili.com/video/av35235691](https://www.bilibili.com/video/av35235691)

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {  
        if(x==z||y==z)
            return true;
        if((x==0||y==0)&z!=0)
            return false;
        if(x+y<z)
            return false;
        int num;
        if(x>y){  
            num=x;
            x=y;
            y=num;
        }
        while(y%x!=0){  
            y=y%x;
            num=y;
            y=x;
            x=num;
        }
        num=x;
        if(z%num==0)  
            return true;
        else 
            return false;
    }
};
```