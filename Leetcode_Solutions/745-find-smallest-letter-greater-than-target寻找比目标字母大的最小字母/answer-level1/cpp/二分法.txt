### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0,high=letters.size()-1;
        while(low<=high){
            int middle=(low+high)/2;
            if(letters[middle]<=target){
                low=middle+1;
            }
            if(letters[middle]>target){
                high=middle-1;
            }
        }
        if(low<letters.size()&&letters[low]>target){
            return letters[low];
        }
        return letters[0];
    }
};
```