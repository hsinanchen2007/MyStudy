### 解题思路
在递归题里面看到的，用递归的方法试着解决
刚开始想反向输出，可是想不到怎么写，后来想到对称轴两边的数字交换就好了，可以用swap函数

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
          if(s.empty())
          return;//极端情况排除
          recursive(s,0,s.size()-1);//递归的初始条件，从两边向中间递归}
    void recursive(vector<char>&s,int start,int end){
        if(start>end)//如果左边的数在右边的数的右边时递归结束
            return;
            recursive(s,start+1,end-1);
            swap(s[start],s[end]);
    }
};
```