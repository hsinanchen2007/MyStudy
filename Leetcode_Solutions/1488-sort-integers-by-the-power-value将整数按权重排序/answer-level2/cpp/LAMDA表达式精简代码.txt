### 解题思路
递归+lamda表达式排序

### 代码

```cpp
class Solution {
public:
    int getKth(int lo, int hi, int k) {
    vector<int> arr(hi-lo+1,0);
    for(int i = 0;i < hi-lo+1;i++) arr[i] = lo+i;
    sort(arr.begin(),arr.end(),[](int a,int b)->bool{
        int quan_a = bushu(a);
        int quan_b = bushu(b);
        if(quan_a == quan_b) return a < b;
        else return quan_a < quan_b;
    });
    return arr[k-1];
    }
    static int bushu(int a){
        if(a == 1) return 0;
        if (a %2 == 0) return 1+bushu(a/2);
        else return 1+bushu(3*a + 1);
    }
};
```