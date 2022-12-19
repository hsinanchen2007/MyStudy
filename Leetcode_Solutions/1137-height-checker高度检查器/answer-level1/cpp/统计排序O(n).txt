### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    
    int heightChecker(vector<int>& heights) {
        
        vector<int> count(101,0);
        int n = heights.size();
         vector<int> h_copy(n);
        //统计排序
        for(int i=0;i<n;i++){
            count[heights[i]]++;
        }
        int pre=0;
        for(int i=0;i<101;i++){
            if(count[i]!=0) {
                count[i]+=pre;
                pre = count[i];
            }
            
        }
        for(int i=n-1;i>=0;i--){
            count[heights[i]]--;
            h_copy[count[heights[i]]] = heights[i];
            
        }
        //统计乱序
         int sum = 0;
        for(int i=n-1;i>=0;i--){
            if(h_copy[i]!= heights[i]) sum++;
            
        }
        return sum;

    }
};
```