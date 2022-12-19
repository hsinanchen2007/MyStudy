class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)   {  
      int begin,end;//移动双指针
      vector<vector<int>> res;
      if(nums.size()<4)  return res;
      sort(nums.begin(),nums.end());//排序

      for(int i=0;i<nums.size()-3;i++){
         for(int j=i+1;j<nums.size()-2;j++)
         {  
            begin=j+1;
            end=nums.size()-1;
            while(begin<end){
              int add=nums[i]+nums[j]+nums[begin]+nums[end];
              if(add==target) {     
                    vector<int> temp(4);
                    temp[0]=nums[i];
                    temp[1]=nums[j];
                    temp[2]=nums[begin];
                    temp[3]=nums[end];
                    if(res.size()==0)
                        res.push_back(temp);
                    else if(res[res.size()-1]!=temp)
                         res.push_back(temp);
                    }
                if(add<target)
                     begin++;
                else
                    end--;
                }
            while(nums[j]==nums[j+1]&&j<nums.size()-2)
                   j++;//去出重复数字
              }
        while(nums[i]==nums[i+1]&&i<nums.size()-2)
                 i++;//去出重复数字
      }       
         
    return res;
    }
};

/*定2个数，再用两个指针进行操作*/UESTC 微笑