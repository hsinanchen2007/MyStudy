
执行用时 :4 ms, 在所有 C++ 提交中击败了95.33% 的用户
内存消耗 :11.3 MB, 在所有 C++ 提交中击败了5.07%的用户

### 解题思路
目标数由两个元素组成，因此，可以确定其中一个元素，然后使用二分搜索法查找另一个元素；


### 代码

```cpp
class Solution {
public:
    int binarySearch(vector<int>& arr,int l,int r,int target){
        if(l>r)
            return -1;
        
        int mid=l+(r-l)/2;
        
        if(arr[mid]==target)
            return mid+1;
        
        if(arr[mid]>target){
            return binarySearch(arr,l,mid-1,target);
        }else{
            return binarySearch(arr,mid+1,r,target);
        }
    }
    
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int j=0;
    
        for(int i=0;numbers[i]<=target;++i){
            j=binarySearch(numbers,i+1,numbers.size()-1,target-numbers[i]);
            if(j>-1){
                result.push_back(i+1);
                result.push_back(j);
                return result;
            }
        }
        return result;
    }
};
```