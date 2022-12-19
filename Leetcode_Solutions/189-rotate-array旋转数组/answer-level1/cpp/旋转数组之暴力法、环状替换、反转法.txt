# 介绍：
暴力法一、二皆超时
环状替换略微有些复杂，通过。
反转法 最优
```
//暴力法一
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int pre,temp;
        //i control the steps
        for(int i=0;i<k;i++){
            pre=nums[nums.size()-1];
            for(int j=0;j<nums.size();j++){
                //exchange the nums[j] and pre
                temp = nums[j];
                nums[j] = pre;
                pre = temp;
            }
        }
    }
};
//暴力法二
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        int i=0;
        //i control the steps
        while(i<k){
            int j = n-2;
            int temp = nums[n-1];
            while(j>=0) {
                nums[j+1] = nums[j];
                j--;
            }
            nums[0] = temp;
            i++;
        }
    }
};
```
![image.png](https://pic.leetcode-cn.com/5d7ee957d770370505ff8d1d853571e50e8bdb017e6fab055a355bfd60168e86-image.png)

```
//环状替换
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        k = k % n;
        int count = 0;
        for(int start = 0;count < n;start++) {
            int current = start;
            int pre = nums[start];
            do{
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = pre;
                pre = temp;
                current = next;
                count++;
            }while(current!=start);
        }
    }
};
```
```
//反转法
class Solution {
private:
    void reverse(vector<int>& nums,int start,int end) {
        while(start<end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};
```






