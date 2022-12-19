一：用set暴力解，时间复杂度O(nlogn), 空间复杂度O(n)
~~~cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> temp;
        for(int i=0; i<nums.size(); i++){
            if(temp.find(nums[i])!=temp.end())
                return nums[i];
            temp.insert(nums[i]);
        }
        return -1;//此return只是为了编译通过,按题目要求不可能执行至此
    }
};
~~~

二：用数组模拟hash表，时间复杂度O(n), 空间复杂度理论O(1), 不会随着数规模增大，但是会随着数据范围的增大而增大
~~~cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int tab[1000001]={0};
        for(int i=0; i<nums.size(); i++){
            if(++tab[nums[i]]>1)
                return nums[i];
        }
        return -1;//此return只是为了编译通过,按题目要求不可能执行至此
    }
};
~~~