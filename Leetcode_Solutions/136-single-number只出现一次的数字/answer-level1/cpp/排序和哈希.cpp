### 解题思路
想到了快排法，但是也没想用sort函数。
哈希法可以用set  count函数就是查找是否存在了，因为set中，count函数只能返回1 或0.
答案应该是用异或 。

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       
            int a=0;
            int flag=0;
            if(nums.size()<=1){
                return nums[0];
            }
            int len=nums.size();
            sort(nums.begin(),nums.end());
            for(int i=0;i<len;i+=2){
                if(i==len-1) return nums[i]; //这个放到前边先判断就好了
                else if(nums[i]!=nums[1+i]){ //就能避免这个[i+1]越界了
                    return nums[i];   //  直接return 不用什么标志位了
                }       
            }
              return -1;        //随便了，反正也到不了这里

            
                    // //快排 别人的
                    // if(nums.size()<=1){
                    //     return nums[0];
                    // }
                    // sort(nums.begin(),nums.end());
                    // int cur;
                    // for(int i=0;i<nums.size();i+=2){
                    //     cur=nums[i];
                    //     if(i==nums.size()-1)  //如果遍历到最后一个元素,说明该元素为single number
                    //         return cur;
                    //     if(cur!=nums[i+1])  //如果当前元素不等于后一个元素即为single number
                    //         return cur;
                    // }               
                    // return -1;



        // //哈希表 
        // set<int> s;
        // for(auto it=nums.begin();it!=nums.end();it++){
        //     if(s.count(*it)){
        //         s.erase(*it);
        //     }else
        //     s.insert(*it);
        // }
        // return *s.begin();

    }
};
```