## 遍历一次，找出第一第二第三大的数
**其实找出先三大的数很容易，这道题麻烦在于“值相同的数，排名相同，比如都排第二”，所以这里“第三大”的数并不是平时说的“第三大”**
```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        //赋一次值，对应的flag加1
        //flag2等于-1是因为第一次赋值是无效的
        //flag3等于-2是因为前两次赋值是无效的
        int flag1=0, flag2=-1, flag3 = -2; 
        for(int i=0; i<len; i++){
            if(nums[i] > max1 || nums[i]==max1 && flag1==0){
                max3 = max2, flag3++;
                max2 = max1, flag2++;
                max1 = nums[i], flag1++; 
            }
            else if(nums[i]==max1) continue;
            else if(nums[i] > max2 || nums[i]==max2 && flag2==0){
                max3 = max2, flag3++;
                max2 = nums[i], flag2++; 
            }
            else if(nums[i]==max2) continue;
            else if(nums[i] > max3 || nums[i]==max3 && flag3==0){
                max3 = nums[i], flag3++;
            }
        }
        if(flag3 > 0) return max3;
        else return max1;
    }
};
```
## 遍历三次，找出第一第二第三大的数
```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        bool flag = false; //falg==true代表存在第三大的数
        for(int i=0; i<len; i++){
            if(max1 < nums[i]) max1 = nums[i];
        }
        for(int i=0; i<len; i++){
            if(max2 < nums[i] && max1 != nums[i]) max2 = nums[i];
        }
        for(int i=0; i<len; i++){
            if(max3 <= nums[i] && max1!=nums[i] && max2!=nums[i]){
                max3 = nums[i];
                flag = true;
            } 
        }
        if(flag==false) return max1;
        else return max3;
    }
};
```
## 利用set----很慢
```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        int len = nums.size();
        for(int i=0; i<len; i++){
            st.insert(nums[i]);
            if(st.size() > 3) st.erase(*(st.begin()));
        }
        if(st.size() >= 3) return *(st.begin());
        else return *(st.rbegin());
    }
};
```