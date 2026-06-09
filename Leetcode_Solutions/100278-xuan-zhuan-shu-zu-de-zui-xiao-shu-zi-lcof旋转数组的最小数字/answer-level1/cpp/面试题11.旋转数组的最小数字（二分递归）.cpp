### 解题思路
核心思路：旋转数组二分后，得到一个新旋转数组和递增数组，只要能找出新旋转数组是哪一半即可递归。
判断方法：比较两部分各自的首末元素大小关系：
        （1）如果两个都是首末递增，且首元素都相同，无法判别，因此递归（start+1,end）;
            如：【10,1,10,10,10】=【10,1,10】+【10,10】，因此递归【1,10,10,10】
        （2）如果两个都是首末递增，且首元素不相等，返回取其中的小者；
            如：【3,4,5,1,2】=【3,4,5】+【1,2】，返回1
        （3）如果两个中有一个递减，就递归这个递减的部分；
            如：【4,5,1,2,3】=【4,5,1】+【2,3】，递归【4,5,1】
        （4）两个都递减不符合旋转数组定义，说明运行时给出的数组就不是旋转数组，就不考虑这种情况了。
执行用时 :8 ms, 在所有 C++ 提交中击败了72.36%的用户
内存消耗 :13.8 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int findMinNum(vector<int>& nums,int start,int end){
        if(start==end){
            return nums[start];
        }
        if(nums[start]<=nums[(start+end)/2]){
            if(nums[(start+end)/2+1]<=nums[end]){
                if(nums[start]==nums[(start+end)/2+1]){
                    return findMinNum(nums,start+1,end);
                }
                return min(nums[start],nums[(start+end)/2+1]);
            }
            else{
                return findMinNum(nums,(start+end)/2+1,end);
            }
        }
        else{
            return findMinNum(nums,start,(start+end)/2);
        }
    }
    int minArray(vector<int>& numbers) {
        int result=findMinNum(numbers,0,numbers.size()-1);
        return result;
    }
};
```