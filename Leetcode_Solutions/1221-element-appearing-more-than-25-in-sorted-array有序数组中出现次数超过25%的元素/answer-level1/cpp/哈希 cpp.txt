### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> hash;
        for(int i =0 ; i<arr.size();i++){
            hash[arr[i]]++;
        }
        int time = arr.size()/4;
       for(int i = 0;i<arr.size();i++){
           if(hash[arr[i]]>time){
               return arr[i];
           }
       }
        return 0;
    }
};
```