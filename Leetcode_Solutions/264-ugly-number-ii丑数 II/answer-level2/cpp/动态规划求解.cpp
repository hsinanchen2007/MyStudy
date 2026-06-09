动态规划进行求解，每一个当前状态依赖于之前的三个状态，求取最小值，为了避免相等相等元素的重复，需要用多个if，而不是if...else if..else...结构，需要注意。
```
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(1,1);
        int i2=0,i3=0,i5=0,i=1;
        while(i++<n){
            int tmp=min(2*res[i2],min(3*res[i3],5*res[i5]));
            res.push_back(tmp);
            if(tmp==2*res[i2]) i2++;
            if(tmp==3*res[i3]) i3++;
            if(tmp==5*res[i5]) i5++;
        }
        return res.back();
    }
};
```