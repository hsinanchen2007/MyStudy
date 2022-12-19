### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size()==1)return numbers[0];
        int low=0,high=numbers.size()-1;
        while(low<high){
            int middle=(low+high)/2;
            if(numbers[low]<numbers[high])return numbers[low];
            else if(numbers[low]<numbers[middle]){
                low=middle+1;
            }
            else if(numbers[middle]<numbers[high]){
                high=middle;
            }
            else{
                low++;
            }
        }
        return numbers[low];
    }
};
```