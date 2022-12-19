```
class Solution {
public:
    struct node{
        int data;
        int num;
    };
    static bool cmp(node a,node b){
        return a.num==b.num?a.data<b.data:a.num<b.num;
    }
    int checked(int n)
    {
        int num=0;
        while (n!=0){
            if (n%2!=0){
                num++;
            }
            n/=2;
        }
        return num;       
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<node>V;
        for(auto i:arr){
            int num=checked(i);
            V.push_back({i,num});
        }
        sort(V.begin(),V.end(),cmp);
        arr.clear();
        for(auto i:V){
            arr.push_back(i.data);
        }
        return arr;
    }
};
```
