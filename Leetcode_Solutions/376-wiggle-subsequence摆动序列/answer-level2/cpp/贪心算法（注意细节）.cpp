class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2) return nums.size();//少于两个元素的序列是摆动序列；
        vector<int> record(nums.size()+1);
        int len=0,count;//count用于计数，来指示下次迭代是波峰还是波谷；
        record[0]=nums[0];

        for(int i=1;i<nums.size();i++)
        {   
            if(nums[i]==record[len]) continue;
            if(nums[i]>record[len]) count=1;
            else  count=0;
             
            if(count==1){
                   if(len!=0&&record[len]>record[len-1])
                       record[len]=nums[i];
                    else{
                       len++;
                       record[len]=nums[i];
                        count=0;  
                    }
 
                 }else{
                     if(len!=0&&record[len]<record[len-1])
                       record[len]=nums[i]; 
                    else{
                      len++;
                     record[len]=nums[i];
                     count=1; 
                    }   
                  }
            }
        return len+1;    
        } 
};
这题的思维其实是标准的贪心思想
[1,17,5,10,13,15,10,5,16,8]
我们希望得到波峰波谷连续的数字序列，但是遇到这个序列的时候，我们却犯了困难，当遍历到10，13的时候我们会想该如何去处理呢？
在1到15存在三个序列
1，17，5，10
1，17，5，13
1，17，5，15
显然，我们应该保留1，17，5，15这个序列，因为15这个波峰最高，自然在后面出现的数字，比这个波峰低的概率就最大，自然形成的序列最大。
根据这个思维，我们可以新建一个记录数组，专门记录已经存在的序列，然后顺序遍历原数组序列，当加入的序列满足构成序列的条件的时候，就直接加入记录数组，否则替换掉记录数组末尾最后一个数字即可，最后返回数组的有效长度即可。