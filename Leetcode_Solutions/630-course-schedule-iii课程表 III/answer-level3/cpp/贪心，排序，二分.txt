先按结束时间给每节课排序，用贪心来选择：
- 当一节课没有足够的时间上时，去检查前面已经选择要上的课中有无比这节课花费的时间多地课，有的话就拿这节课去替换它，因为①这节课的时间短，替换后结束时间也会提前，只会对后面的课有利；②这节课的最晚结束时间比前面的课都晚，可以确保这节课能上完。
- 可以用一个数组来储存前面已经选了的课的花费时间，并按升序排列，这样在比花费时间时只需和最后一个比即可，插入时要用二分找到应该插入的位置。
```
class Solution {
    static bool cmp(vector<int> a,vector<int> b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);//按结束时间从小到大排序
        vector<int>vec;
        int res=0,last=0;
        for(auto c : courses){
            if(c[1]-c[0]<0) continue;
            if(c[1]-c[0]<last){//在前面的上的课的条件下这节课上不了
                if(c[0]>vec.back()) continue;
                last-=vec.back();//减去最长的时间
                vec.pop_back();
            }
            else{
                res++;
            }
            int l=0,r=vec.size()-1;
            while(l<r){
                int mid=l+r>>1;
                if(vec[mid]>=c[0]) r=mid;
                else l=mid+1;
            }
            if(!vec.size()||vec[l]>c[0]) vec.insert(vec.begin()+l,c[0]);
            else vec.insert(vec.begin()+l+1,c[0]);
            last+=c[0];
        }
        return res;
    }
};
```
