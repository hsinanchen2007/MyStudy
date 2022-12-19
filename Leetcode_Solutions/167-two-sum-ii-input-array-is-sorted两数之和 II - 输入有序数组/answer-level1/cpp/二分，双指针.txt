### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len=numbers.size()-1,temp,left,right,mid;
        //二分法
        for(int i=0;i<len;i++){
            temp=target-numbers[i];
            left=i+1;
            right=len;
            while(left<right){
                mid=left+(right-left)/2;
                if(numbers[mid]<temp){
                    left=mid+1;
                }
                else{
                    right=mid;
                }
            }
            if(numbers[left]==target- numbers[i]) 
            return {i+1,left+1};
        }
            return {-1,-1};
           

        /*双指针算法
        for(int i=0,j=numbers.size()-1;i<numbers.size();){
            if(numbers[i]+numbers[j]==target)
                return {i+1,j+1};
            if(numbers[i]+numbers[j]<target)
                i++;
            else
                j--;
        }
        return {-1,-1};
        */
    }
};
```