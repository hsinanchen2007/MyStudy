### 解题思路
1,2,3
插入法，第一次只有1，第二次2可以插入到1前面后面2，1；1，2；第三次3k有三个位置可以插入，递归调用1，向量大小为3时保存结果。

### 代码

```cpp
class Solution {
public:
    void insert(vector<int>temp,int j,vector<vector<int> >&res,vector<int>nums)
    {
      
        if(j<nums.size())
        for(int i=0;i<=j;i++)
        {   
        	vector<int>temp2(temp);		    
            temp2.insert(temp2.begin()+i,nums[j]);         
            insert(temp2,j+1,res,nums);
            
        } 
		else
		{
			res.push_back(temp);
			
		}      

    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>res;
        vector<int>temp;
        insert(temp,0,res,nums);     
        return res;
      

    }
};
```