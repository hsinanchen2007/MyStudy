### 解题思路
此处撰写解题思路

### 代码

```cpp

#include <algorithm>
#include <functional>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> laji_num;
        
         cout<<"一共："<<nums.size()<<endl;
        for(int i =0;i<nums.size();i++){

            int repeated_num=0;
            vector<int>::iterator location_index;
            location_index=find(laji_num.begin(),laji_num.end(),nums[i]);
            if(location_index==laji_num.end()){
            //前三句是为了避免把本来就不是最多数的数字重复统计

                for(int j =0;j<nums.size();j++){
                    if(nums[i]==nums[j])
                    repeated_num++;
                }
                cout<<nums[i]<<":"<<repeated_num<<endl;

                if(repeated_num>nums.size()/(double)2){
                    cout<<"find:"<<repeated_num<<"个"<<nums[i]<<endl;
                        return nums[i];
                    //只要有一次找到了重复数字多于整体的的个数一半后，它就一定是要找的数了
                }else{
                    laji_num.push_back(nums[i]);
                }
            }
         
        }
        
        return -1;
   

      
    }

   
};
```