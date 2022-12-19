### 解题思路
這道題是兩個數字比較並改變一次，因此改變的數只可能在兩者之間
因爲要保證整個序列是非遞減，所以找的是極大值極小值改變
改變一位數字，極大值則削平，極小值則填補，然後看更改後能否奏效

### 代码

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool is=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(i<nums.size()-1)//防止溢出
                    if(nums[i-1]>nums[i+1])
                    {
                        nums[i-1]=nums[i];//削平凸起的值
                    }
                    else
                    {
                        nums[i]=nums[i+1];//填補凹進去的值
                    }
                else{//倒數某第一位小於倒數第二位
                    nums[i]=nums[i-1];
                }
                    //更改數組
                is=true;
                break;
            } 
        }
        if(is){//調整過
          for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                nums[i]=nums[i+1];//調整過還有
                return false;
            } 
        }
        }
        return true;//不需要改，已經是了
    }
};
```