### 解题思路
方法一：大多数同学使用的方法 hash表，这里我使用的是unordered_set, unordered_set 是一个hash表，增删查改运算它的平均时间复杂度为O(1),最坏的情况下也就是出现reflsh情况下为O(n)
具体解法，已经在代码中详细注释了！

方法二：用sort方式排序（时间复杂度不满足题目要求），然后进行循环判断，也不需要去重，遇到重复的元素就不累加计算即可，简单明了，具体注释也在代码里面表明了！哈哈哈

### 代码

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //解法一：hash set方法
        if(nums.size() == 0){
            return 0;
        }
        int maxlen = 1;
        int len = 1;
        unordered_set<int> hashset(nums.begin(),nums.end());

        for(int val:hashset){

            if(hashset.count(val-1) != 0){//如果存在val-1这个数，说明val不是连续序列的起始元素，所以跳过，继续找起始元素
                continue;
            }

            while(hashset.count(val+1)!=0){
                len++;
                val++;
            }
            maxlen = max(maxlen,len);
            len = 1;
        }

        return maxlen;

      // 解法二：sort排序方法，虽然时间复杂度不满足题目要求
      /*  int maxsum = 1;
        int temp = 1;
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(),nums.end());

        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]-1){
                temp += 1;
                maxsum = max(maxsum,temp);
            }
            else if(nums[i] == nums[i+1]){//出现连续重复的元素就跳过累加计算
                continue;
            }
            else{
                
                temp = 1;//连续序列中断，将累加器temp赋值为1，只要打算累加 说明有其实元素，故temp开始为1.
            }
        }

        return maxsum; */
    }
};
```