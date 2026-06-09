### 解题思路
一开始看错了，还以为是不分谁谁谁，直接排序然后求相邻的最小差就好了...
然后看清楚了之后确定了思路：
直接O(mn)的复杂度应该不行，肯定要优化一下，所以对a中的每一个元素，都采用在b中二分求最小差的方法。
这样复杂度就大概到了O(mlogn)。

### 代码

```cpp
#include<algorithm>
class Solution {
    int temp;
public:
    double abs(double get){
        return get<0?-get:get;
    }
    double binarySearch(vector<double>& a, vector<double>& b,int aIndex,int i,int j){
        if(j==i){
            return abs(a[aIndex]-b[i]);
        }
        if(j<i){
            return DBL_MAX;
        }
        double result=DBL_MAX;
        if(a[aIndex]<=b[i]){
            return b[i]-a[aIndex];
        }
        if(a[aIndex]>=b[j]){
            return a[aIndex]-b[j];
        }
        int middle=(i+j)/2;
        double x,y,z;
        x=binarySearch(a,b,aIndex,i,middle-1);
        y=abs(b[middle]-a[aIndex]);
        z=binarySearch(a,b,aIndex,middle+1,j);
        temp=(x<y?x:y);
        return (temp<z)?temp:z;
    }

    int smallestDifference(vector<int>& a, vector<int>& b) {
        vector<double> c;
        vector<double> d;
        int len1=a.size(),len2=b.size();
        for(int i=0;i<len1;i++){
            c.push_back(static_cast<double>(a[i]));
        }
        for(int i=0;i<len2;i++){
            d.push_back(static_cast<double>(b[i]));
        }
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());

        //下面的操作复杂度为mlogn
        double min=DBL_MAX;
        double tempMinx=DBL_MAX;
        for(int i=0;i<len1;i++){
            //在d中进行二分查找
            tempMinx=binarySearch(c,d,i,0,d.size()-1);
            min=(min<tempMinx)?min:tempMinx;
        }
        return min;
    }
};
```