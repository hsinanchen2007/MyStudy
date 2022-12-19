### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void quick_sort(vector<int>& q, int l, int r){
              if(l < r)
              {
                 int i = l, j = r, t = q[l];

                  while(i < j)
                  {
                    while(i < j && q[j] > t)
                        j--;
                    if(i < j)
                        q[i++] = q[j];

                    while(i < j && q[i] < t)
                        i++;
                    if(i < j)
                        q[j--] = q[i];
                  }
                   q[i] = t;
              quick_sort(q, l, i - 1);
              quick_sort(q, i + 1, r);
              }
             
          }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
         
        vector<int> res;
          quick_sort(arr, 0, arr.size()-1);
          for(int i=0;i<k;i++) 
             res.push_back(arr[i]);
          return res;
    }
};



class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
            sort(arr.begin(),arr.end());
            return vector<int> (arr.begin(),arr.begin() + k);
            
    }
};
```
