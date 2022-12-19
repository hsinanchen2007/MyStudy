和官方题解类似，加入了自己的注解
```
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> vec(2,0);//存放最后结果
        map<int,int> map1;//存放出现次数
        for(int i=1;i<=nums.size();i++){
            map1[i]+=1;//1~n之间的数先初始化设为1
            map1[nums[i-1]]+=1;//累加nums中出现的数的次数
        }
        for(int i=1;i<=nums.size();i++){
            if(map1[i]==3) vec[0]=i;//重复的数的次数为3
            else if(map1[i]==1) vec[1]=i;//缺失的数的次数为1
        }
        return vec;
    }
};
```
