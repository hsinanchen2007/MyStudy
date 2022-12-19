解法1：一位一位的移动，但是超出了时间限制
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>=nums.size())
            k%=nums.size();
        int temp=0;
        for(int i=0;i<k;i++){
            temp=nums[nums.size()-1];
            for(int j=nums.size()-1;j>0;j--){
                nums[j]=nums[j-1]; 
            }
            nums[0]=temp;
        }
    }
};
```
解法2：用一个数组保留后k位数组，将前面的数组向后移动k位，再写入前面的数组
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       if(k>=nums.size())
            k%=nums.size();
        if(k!=0)
        {
            //用数组保留后k位数据
            vector<int> temp(k);
            int tempIndex=0;
            //将前面数据移动k位
            for(int i=nums.size()-k;i<nums.size();i++){
                temp[tempIndex]=nums[i];
                tempIndex++;
            }
            for(int j=nums.size()-1;j>=k;j--){
                nums[j]=nums[j-k]; 
            }
            //将后k位数据赋值到前面k位
            for(int x=0;x<k;x++){
                nums[x]=temp[x]; 
            }
        }
        
    }
};
```
ps：注意tempIndex的定义，一开始没有定义报错数组越界