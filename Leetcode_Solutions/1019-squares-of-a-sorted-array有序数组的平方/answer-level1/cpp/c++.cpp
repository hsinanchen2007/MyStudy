### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>B;
  vector<int>::iterator it;
  for(it=A.begin();it!=A.end();it++){
      B.push_back((*it)*(*it));
  }
  sort(B.begin(),B.end());
  return B;
    }
};
```