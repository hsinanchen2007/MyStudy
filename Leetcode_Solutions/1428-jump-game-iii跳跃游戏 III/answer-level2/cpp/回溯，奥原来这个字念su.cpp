### 解题思路
我觉得这道题最大的收获就是原来溯念su  -_-
每个点接下来会有2种走法，一下子会想到回溯算法，思路比较简单，bugdead了一次，是因为没有考虑到内循环，用一个unordered_set，记录已经走过的下标（如果下次再走到已经记录过的下标，说明是死循环了），可以解决这个问题。

### 代码

```cpp
class Solution {
public:
    //回溯
    bool result = false;
    unordered_set<int>set1;
    bool canReach(vector<int>& arr, int start) {  func(arr,start);  return result;  }
    void func( vector<int>& arr,int i){
        if(i >=arr.size() || i < 0  ||  set1.count(i) == 1  ) return;
        if(arr[i] == 0){  result = true;  return;  }
        set1.insert(i);//记录已经走过的下标，防止内循环
        func(arr,i+arr[i]);
        func(arr,i-arr[i]);   
    }
};
```