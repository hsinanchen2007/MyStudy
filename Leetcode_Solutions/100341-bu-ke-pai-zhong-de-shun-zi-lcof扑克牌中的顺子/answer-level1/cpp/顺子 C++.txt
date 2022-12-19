```
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //排序，便于遍历操作
        int count = 0; //count记0出现的次数
        while(nums[count] == 0) count++;
        if(nums[4]-nums[count]>4) //非零的最大最小值差值需<=4
            return false;
        for(int i = count;i<4; i++){ //遍历非零序列
            if(nums[i+1]==nums[i]) //若遇相等返回false
                return false;
            count -= nums[i+1]-nums[i]-1; //差值>1时用0填补
        }
        return count>=0; //检查0的使用是否超额
    }
};
```
举几个例子：
1. `[0,0,1,1,5]` 
    相等返回false

2. `[0,0,1,2,5]` 
    0数目 = 5-2+1，最后`count==0`，只能生成一种序列`[1,2,3,4,5]`

3. `[0,0,0,9,11]`
    0数目 > 11-9+1，最后`count==2`，可能生成多种序列如`[8,9,10,11,12]`或`[7,8,9,10,11]`

4. `[0,0,0,0,7]`
    你有王炸你说了算（皮一下很开心：P）

