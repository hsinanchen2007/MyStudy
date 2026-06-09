C++，没有自己模拟，调用的库函数，三种方法。第一种很慢，后两种都0ms。
给我家丫头写的：
我觉得这句话挺好，“尽量不要自己造轮子，一是这样减少出错的可能，二是比较无脑，保护脑细胞”
所以直接用库函数吧
```
class Solution {
public:
    int myAtoi(string str) {
        // long long ret=atol(str.c_str());
        // if(ret>INT_MAX) ret=INT_MAX;
        // else if(ret<INT_MIN) ret=INT_MIN;
        // return ret;

        // long long ret=0;
        // sscanf(str.c_str(),"%lld",&ret);
        // if(ret>INT_MAX) ret=INT_MAX;
        // else if(ret<INT_MIN) ret=INT_MIN;
        // return ret;

        // stringstream ss(str);
        // long long ret=0;
        // ss >> ret;
        // if(ret>INT_MAX) ret=INT_MAX;
        // else if(ret<INT_MIN) ret=INT_MIN;
        // return ret;
    }
};
```
最后一种流输入可以不用判断是否越界，完全可以用int来代替long long 越界会自动换成最大值或最小值