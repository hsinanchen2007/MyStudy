```c++ []
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
     vector<int> res;
     for(int i=0;i<nums.size();i++)  //size后记得加（）
     {
         nums[abs(nums[i])-1]=-abs(nums[abs(nums[i])-1]);
     }
     for(int i=0;i<nums.size();i++)
     {
         if(nums[i]>0) {res.push_back(i+1);} //加在后面
     }
       return res;
    }
};
```
```python []
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        s=set(nums)  #set函数用来输出不重复的元素
        res=[]
        for i in range(1,len(nums)+1):
            if i not in s:
                res.append(i)
        return res                 
```
```c []
//笨办法
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
       *returnSize=0;
       int a[100000]={0};
       int* p=(int*)malloc(sizeof(int)*numsSize); //动态内存分配，memory allocation
       for(int i=0;i<numsSize;i++)
       {
           a[nums[i]-1]=1;
       }
       for(int i=0;i<numsSize;i++)
       {
           if(a[i]!=1)
           {
              p[(*returnSize)++]=i+1;  //相当于当数组用
           }
       }
       return p;   //要求返回动态形式的
       }
```


用正负号来表示对应位置上的数字是否出现过。

比如数组里出现元素3，那么就使3-1=2号位置上的元素变为负数。
每个元素都遍历一遍之后，哪个位置上的元素还是正数，那么数字‘该位置+1’就没有出现过。
同理可用来分析数组中哪些元素出现了奇数次，哪些出现了偶数次（出现0次认为偶数次）。
