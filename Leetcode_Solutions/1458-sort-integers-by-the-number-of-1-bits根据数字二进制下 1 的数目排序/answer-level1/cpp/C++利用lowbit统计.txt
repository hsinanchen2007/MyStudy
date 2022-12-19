```cpp
class Solution {
public:
    typedef struct ss{
        int n,x;
    }ss;
    static bool cmp(ss a,ss b){
        if(a.n==b.n)
            return a.x<b.x;
        return a.n<b.n;
    }
    int lowbit(int x){
        return x&-x;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<ss> a(arr.size());
        for(int i=0;i<arr.size();i++){//结构体存储
            a[i].x=arr[i];
            a[i].n=0;
            while(arr[i]){//统计1的个数
                a[i].n++;
                arr[i]-=lowbit(arr[i]);
            }
        }
        sort(a.begin(),a.end(),cmp);//排序
        for(int i=0;i<arr.size();i++)//赋值
            arr[i]=a[i].x;
        return arr;
    }
};
```
