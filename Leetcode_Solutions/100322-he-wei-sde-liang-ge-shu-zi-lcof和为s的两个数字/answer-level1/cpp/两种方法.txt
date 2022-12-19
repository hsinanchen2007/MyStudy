# 1.用map存储(空间开销大)
key:target-nums[i]   value:nums[i]
意思是说，nums[i]将自己要找的数存进去，当遍历到自己要找的数时，配对成功
```
vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> a;//存储某数要找的值与该数的键值对
    vector<int> res(2);
    for(int i=0;i<nums.size();i++){
        if(a.count(nums[i])==0){
            a[target-nums[i]] = nums[i];
        }
        else{
            res[0] = a[nums[i]];
            res[1] = nums[i];
            break;
        }
    }
    return res;
}
```
# 2.双指针(空间开销小)
本题特殊之处在于所给出的序列是递增序列，排好序的数组我们要想到可以用双指针
i只能向右，而j只能向左
如果nums[i]+nums[j]==target,结果显然
如果nums[i]+nums[j]>target,说明右边的数应当小一些，j--
如果nums[i]+nums[j]<target,说明左边的数应当大一些，i++
在判断中尽量不要带算式，容易增加时间。
如果将需要的变量尽量先定义好，可以满足计算要求，这样会比在循环中定义省更多时间
```
vector<int> twoSum(vector<int>& nums, int target) {
    int i=0,j=nums.size()-1,sum;
    vector<int> res;
    while(i<j){//确保不重复
        sum = nums[i] + nums[j];       
        if(sum==target){
            res.push_back(nums[i]);
            res.push_back(nums[j]);
            break;
        }
        else if(sum>target)
            j--;
        else
            i++;
    }
    return res;
}

```




