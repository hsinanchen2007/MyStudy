```
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        int sum = INT_MAX;
        // 方法1：双重循环
        // for(int i=0;i<list1.size();i++)
        // {
        //     for(int j=0;j<list2.size();j++)
        //     {
        //         if(list1[i] == list2[j])
        //         {
        //             if(i+j<sum)
        //             {
        //                 res.clear();
        //                 res.push_back(list1[i]);
        //                 sum = i+j;
        //             }
        //             else if(i+j==sum)
        //             {
        //                 res.push_back(list1[i]);
        //             }
        //             else
        //             {
        //                 continue;
        //             }
        //         }
        //     }
        // }
        
        
        // 方法2：单重循环
        for(int i=0;i<list1.size();i++)
        {
            auto it = find(list2.begin(),list2.end(),list1[i]);
            if(it == list2.end())
                continue;
            
            int j = it - list2.begin();
            if(i+j<sum)
            {
                res.clear();
                res.push_back(list1[i]);
                sum = i+j;
            }
            else if(i+j==sum)
            {
                res.push_back(list1[i]);
            }
        }
        return res;
    }
};
```