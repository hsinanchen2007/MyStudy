### 解题思路
此处撰写解题思路
哈希终于有用了，醉了，忘了排序时，
1.哈希的int型键可以是负的，别忘了哈希是什么类型的值都支持。
2.负数的排序和正数不同，10，8，7，-7，-8，-10
### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        if(arr.size()==0) return false;
        map<int,int>maps;
        sort(arr.rbegin(),arr.rend());
        for(int i=0;i<arr.size();i++){
            if(maps.count(arr[i]*2)) return true;
            if(arr[i]%2==0&&maps.count(arr[i]/2)) return true;  //除的话要有arr[i]%2==0
            maps[arr[i]]++;
        }
        return false;
    }
};
```