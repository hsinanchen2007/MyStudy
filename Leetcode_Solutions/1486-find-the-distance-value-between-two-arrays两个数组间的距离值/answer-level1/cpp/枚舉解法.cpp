### 解题思路
枚舉法，代碼如下。
爲了省時，如果有違規的則Break.
因爲會Break,所以并不會一直循環到arr2的末尾。如果循環到了，則説明是符合條件的元素，計數加一。
### 代码

```cpp
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
       int len1 = arr1.size(),len2 = arr2.size(),count = 0;
       for(int i=0;i<len1;i++){
           int j = 0;
           for(j=0;j<len2;j++){
               if(abs(arr1[i]-arr2[j])<=d) break;
        }
           if(j == len2) count++;
       } 
       return count;
    }
};
```