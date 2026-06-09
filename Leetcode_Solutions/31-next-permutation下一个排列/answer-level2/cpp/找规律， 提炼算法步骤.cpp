### 解题思路
难点在于题目给的测试的例子太少了， 不足以支撑寻找规律， 需要自己多寻找。 另外要求常数空间，即O(1), 就采用遍历的方式时间换空间。

算法步骤：
1. 从右到左扫描， 确认是存在次大的序列
2. 如果不存在， 则返回从小到大的序列
3. 如果存在， 则先更新左边的数字为次大的数， 再依次更新剩下的数为当时最小的数即可


### 代码

```cpp
class Solution {
public:
    void swapNums(int& n1, int& n2){
        int tmp = n1;
        n1 = n2;
        n2 = tmp;
    }
   
    void nextPermutation(vector<int>& nums) {
       if(nums.size() <= 1) return;

       int size = nums.size();
       int found = 0;
       //int min_index = size-1;

       for(int k=size-1; k>=1; k--){ //nums至少存在2个元素, 而且不是第一个数字
            if(nums[k] > nums[k-1]) { //存在次大的列表
            int cur = k;
            int gti = -1, lti = -1;
            for(int i=cur; i<nums.size(); i++){
                 //       cout<<"here"<<endl;
               // cout<<"i: "<<i<<" "<<nums[i]<<endl;
               // cout<<"gti: "<<gti<<" "<<endl;

                if(nums[i]>nums[k-1]){
                    if(gti == -1){
                        gti = i;
                    } else if(nums[i]<nums[gti]){
                        gti = i;
                    }
                }
            }
            if(gti!=-1){
                swapNums(nums[k-1], nums[gti]);
               // cout<<"Nums[0]: "<<nums[0]<< " "<<nums[gti]<<endl;
                found=1;
            }
            
           // cur++;
            
            while(cur<nums.size()){
             //   cout<<"here2 "<<cur<<endl;

                for(int i=cur; i<nums.size(); i++){
                    if(nums[i]<nums[cur]){
                        if(lti == -1){
                            lti = i;
                        }else if(nums[i]<nums[lti]){
                            lti = i;
                        }
                    }
                }
                if(lti!=-1){
                 swapNums(nums[cur], nums[lti]);
                }
                lti = -1;
                cur++;
            }
                return;
            } 
       }
       if(found == 0 && nums[1] > nums[0]){ //第一个数字需要变换
            int cur = 1;
            int gti = -1, lti = -1;
            for(int i=cur; i<nums.size(); i++){
                 //       cout<<"here"<<endl;
               // cout<<"i: "<<i<<" "<<nums[i]<<endl;
               // cout<<"gti: "<<gti<<" "<<endl;

                if(nums[i]>nums[0]){
                    if(gti == -1){
                        gti = i;
                    } else if(nums[i]<nums[gti]){
                        gti = i;
                    }
                }
            }
            if(gti!=-1){
                swapNums(nums[0], nums[gti]);
               // cout<<"Nums[0]: "<<nums[0]<< " "<<nums[gti]<<endl;
                found=1;
            }
            
           // cur++;
            
            while(cur<nums.size()){
             //   cout<<"here2 "<<cur<<endl;

                for(int i=cur; i<nums.size(); i++){
                    if(nums[i]<nums[cur]){
                        if(lti == -1){
                            lti = i;
                        }else if(nums[i]<nums[lti]){
                            lti = i;
                        }
                    }
                }
                if(lti!=-1){
                 swapNums(nums[cur], nums[lti]);
                }
                lti = -1;
                cur++;
            }
       }

       if(found == 0){ //不存在次大的列表
            for(int j=0; j<size/2; j++){
                swapNums(nums[j], nums[size-1-j]);
            }
            return;
       }


       return;

    }
};
```