## 排序+一次遍历

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
       int count = 0;
       for (int i = 1; i< A.size(); i++){
            if (A[i] <= A[i-1]){
               count += (A[i-1] +1 - A[i]);
               A[i] = A[i-1] +1;
            }
       }
       return count;
    }
};
```

## map记录数字出现次数并计算

1. map记录 值出现的次数
2. 利用map的key是有序的，计算需要移动的次数

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
       map<int, int> mp;
       for (int i =0; i< A.size(); i++){
           mp[A[i]]++;
       }
       int count = 0;
       for (auto &n: mp){
            if (n.second > 1){
               count = count + n.second -1;
               mp[n.first+1] = mp[n.first+1] + n.second -1;
            }
       }
       return count;
    }
};
```