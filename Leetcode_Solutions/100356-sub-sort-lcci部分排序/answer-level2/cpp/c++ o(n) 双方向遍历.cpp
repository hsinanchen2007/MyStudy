- 正向扫描：找到正向最后一个元素小于max的坐标，max此时代表当前元素及之前的最大值
- 逆向扫描：找到逆向最后一个元素大于min的坐标，min此时代表当前元素及之后的最小值

```cpp
static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
       int left = -1;
       int right = -1;
       int max = INT_MIN;
       int min = INT_MAX;
       int n = array.size();
	   int i = 0;
       while(i<n){
           max = (max>array[i])?max:array[i];
           if(array[i]<max) right = i;
           min = (min<array[n-i-1])?min:array[n-i-1];
           if(min<array[n-i-1]) left = n-i-1;
           i++;
       }
       return {left,right};
    }
};
```
