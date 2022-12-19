### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i=0;
        int j=numbers.size()-1;
        int mid=0;
        while(i<j){
            mid=i+(j-i)/2;
            if(numbers[mid]>numbers[j]){
                i=mid+1;
            }
            else if(numbers[mid]<numbers[j]){
                j=mid;
            }
            else {
                j=j-1;
            }
            

        }
        return numbers[i];
    }
};
```