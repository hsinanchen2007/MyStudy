### 解题思路
用map存相应数字的个数，然后查找（因为无序所以效率更低吧）

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k){
        int count=0;
        vector<int> target;
      map<int,int> m;
      map<int,int>::iterator it;
        for(auto i: arr){
            ++m[i];
        }
        it=m.begin();
        for(;it!=m.end();++it){
            if(k<=0)
            break;
            count=k<m[it->first]?k:m[it->first];
        while(count--){
            target.push_back(it->first);
            
                    }
                    k=k-m[it->first];
        }
       
        return target;
    }
};
```