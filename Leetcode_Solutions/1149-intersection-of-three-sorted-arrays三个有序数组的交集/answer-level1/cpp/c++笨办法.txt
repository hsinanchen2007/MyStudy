先找两个的交集，然后找两个交集的交集。......
```
class Solution {
public:
    vector<int> Intersection(vector<int>&arr1,vector<int>&arr2)
    {
        vector<int> ret;
        int p1 = 0;
        int p2 = 0;
        while(p1 < arr1.size() && p2 < arr2.size())
        {
            //cout <<"p1 : "<<p1 <<"  p2: "<<p2<<endl;
            if(arr1[p1] < arr2[p2])
            {
                ++p1;
            }
            else if(arr1[p1] > arr2[p2])
            {
                ++p2;
            }
            else 
            {
                ret.push_back(arr1[p1]);
                ++p1;
                ++p2;
            }
        } 
        return ret;
    }
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> t1;
        vector<int> t2;
        vector<int> t3;
        t1 = Intersection(arr1,arr2);
        t2 = Intersection(arr2,arr3);
        t3 = Intersection(t1,t2);
        return t3;
    }
};
```
