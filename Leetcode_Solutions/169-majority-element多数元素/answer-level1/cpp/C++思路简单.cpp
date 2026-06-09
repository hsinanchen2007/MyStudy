### 解题思路
统计出现的次数，减为0时换成下一个元素为主元素，最后再统计是否大于n/2次

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int re;
        int i,j,n=1;
        int maj=nums[0];
        for(j=1;j<nums.size();j++){
         if(nums[j]==maj)
          n++;
         else{
             if(n<=1) {
               maj=nums[j];
               n=1;
                continue;
                      }
             else n--;
             } 
         }
         while(n>0) {
             n=0;
             for(i=0;i<nums.size()-1;i++){
             if(nums[i]==maj) n++; 
             else continue;
             }
             break;
             }
         if(n>=nums.size()/2)
            return maj;
            return re;
            
    }
};
```