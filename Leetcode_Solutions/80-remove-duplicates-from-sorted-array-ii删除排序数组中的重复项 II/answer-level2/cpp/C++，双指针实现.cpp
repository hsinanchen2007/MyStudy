class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        int done=0,search=1;
        int cnt=1;
        for(search=1;search<nums.size();search++){
            if(nums[search]==nums[done]){
                if(cnt<2){
                    nums[++done]=nums[search];
                    cnt++;
                }
                    
            }
            else if(nums[search]!=nums[done]){
                cnt=1;
                nums[++done]=nums[search];
            }
                
        }
        return done+1;
    }
};

其实很简单，一个指针指向已经完成的前半部分，另一个指针负责搜索。

![123.jpg](https://pic.leetcode-cn.com/dd1d4c4702603d4b7a685c2238a5b6eaf54dcae4d02f45f6adafda70f4795ee8-123.jpg)

那么待处理位置时候被填入search指针的值，看两种情况：
1.如果两个数不相等，直接填；
2.如果search的值和这个done的值相等，那就需要前面处理好的列表中后面有几个done的值了，如果超过2个是不会被填入的，search指针就继续搜索。

剩下的就看代码实现了。