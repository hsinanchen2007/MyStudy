### 解题思路
稍微改了一下剑指代码（书上原代码超时），因为与左边数字比，所以时间效率不如直接与右边比
### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.empty())
            return {};
        int indexBegin=0;
        int indexEnd=numbers.size()-1;
        int indexMid=0;      
        while(numbers[indexBegin]>=numbers[indexEnd])
        {            
            //首尾重合退出循环
            if(indexBegin==indexEnd)
            {
                break;
            }
            indexMid=(indexBegin+indexEnd)/2;      
            if(numbers[indexMid]==numbers[indexBegin])
                indexBegin++;
            else 
                if(numbers[indexMid]>numbers[indexBegin])
                    indexBegin=indexMid+1;
                else 
                    indexEnd= indexMid;       
        }    
        return numbers[indexBegin];
    }
};
```