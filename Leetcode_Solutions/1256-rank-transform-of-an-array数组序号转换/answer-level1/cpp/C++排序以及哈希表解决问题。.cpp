### 解题思路
排序以后数组按序增大，用pre记录最近出现的新数据，并用count记录当前为第几大的数据，然后遍历数组k，第i个数据 k【i-1】如果不等于pre则说明这个数比前一个数大，并且count++，将数据和对应的第几大放入哈希表。最后一次遍历数组。得出结果。
![image.png](https://pic.leetcode-cn.com/4a540abf14b32d5b27c532ec1fa8de65b683a1943e98fc8d863f7919413418ee-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       if(arr.size()==0) return {};
       unordered_map<int,int> pair;
       vector<int> k=arr;
       sort(k.begin(),k.end());
       int count=1,pre=k[0];
       pair[pre]=count;
       for(int i=0;i<arr.size();i++)
       {
          if(k[i]!=pre)
          {
              count++;
              pair[k[i]]=count;
              pre=k[i];
          }
       }
       for(int i=0;i<arr.size();i++)
       {
          k[i]=pair[arr[i]];
       }
       return k;
    }
};
```