Java的代码在内存和时间上都优于90%+的提交，感觉还行
思路上感觉有三点最主要：
1. 这道题中，数列中具体是什么数其实并不重要，例如[1,2,2,3,3,4]与[3,4,4,5,5,6]的结果并没有什么区别，我们唯一关注的是：最小的数从哪个索引开始和结束（最小的数当然从0开始了），其次是第二小的数、第三小的数。。。直到最大的数。同样对于子序列，我们只关注他的长度和它是否可以添加新的数字
2. 数组中的数字优先加在长度较小的子序列末尾。为了观察直观我将数列这样排列，每一行代表一个凑成的子序列：

    ```
    eg 1：
    1   2   3   4
        2   3   4   5   6
                4   5   6   7   8
                                8   9   10
    ```
    虽然我们也可以这样排列：
    ```
    eg 2：
    1   2   3   4
        2   3   4   5   6   7   8
                4   5   6
                                8   9   10
    ```
    但是我想说的是，任何一个符合题目规则的数列，虽然可以像eg2这样组合，但一定可以写成eg1的形式
    因为如eg2，第三行截止到 6 时已经满足长度为3，则它上面的子序列截止到 6 时的长度一定大于3，如果第三行合规，则上面的子序列一定合规，接下来的7，8可以优先加在最低行的末尾。也可以理解为优先加在较短序列的末尾
3. 若数组中某个数（n）与它前面的数的差大于1，则可以使用递归：求解原数组相当于求解这个数组从n往后的子数组，如下面这个例子eg3，解决[1,2,2,3,3,4,6,7,8,9]可递归解决[6,7,8,9]
    
    ```
    eg 3
    1   2   3
        2   3   4
                        6   7   8   9
    ```



因此我的方法是，对数组中每个数（记为nums[i]）遍历，根据nums[i]的值维护一个记录子序列长度的列表rec。

而recHead、recTail和recIndex是rec上的三个索引，recHead与recIndex之间的子序列以nums[i]-1结尾（等待添加一个nums[i]），recIndex与recTail之间以nums[i]结尾（已将添加过了），只有recHead与recTail之间的序列才是我们需要研究的，recIndex也只能在这两个端点之间移动。recIndex初始位于研究区间末尾（recTail-1），然后rec[recIndex]++后向前移动一位，超过recHead后再返回区间末尾。

对于每一个nums[i]：
![流程图.jpg](https://pic.leetcode-cn.com/0f3aaa1d88fc4e1b9f66d67a9b686bd505c6f1235ddce03c5ea6c1c9dbe5da22-%E6%B5%81%E7%A8%8B%E5%9B%BE.jpg)


Python我还不太熟，写得有些繁琐，大家参考一下思路就好了

```python3 []
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        rec = [1, ]
        recHead = 0
        recIndex = 0
        for i in range(1,len(nums)):
            if nums[i] == nums[i-1]:
                if recIndex != len(rec)-1:
                    rec[recIndex] += 1
                    recIndex -= 1
                    if recIndex < recHead:
                        recIndex = len(rec)-1
                else:
                    rec.append(1)
                    recIndex = len(rec)-1
            elif nums[i] != nums[i-1]+1:
                for n in rec[recHead:]:
                    if n < 3:
                        return False
                return self.isPossible(nums[i:])
            elif recIndex == len(rec)-1:
                rec[recIndex] += 1
                recIndex -= 1
                if recIndex < recHead:
                    recIndex = len(rec)-1
            else:
                while recHead != recIndex+1:
                    if rec[recHead] < 3:
                        return False
                    recHead += 1
                rec[len(rec)-1] += 1
                recIndex = len(rec)-2
                if recIndex < recHead:
                    recIndex = len(rec)-1
        for r in rec[recHead:]:
            if r < 3:
                return False
        return True
```
```Java []
class Solution {
    public boolean isPossible(int[] nums) {
        if(nums.length<=2)
            return false;
        int[] rec=new int[nums.length/3+1];
        int recHead=0,recTail=1;
        int recIndex=0;
        rec[0]=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]==nums[i-1]){
                if(recIndex != recTail-1){
                    rec[recIndex--]++;
                    if(recIndex<recHead)recIndex = recTail-1;
                }else if(recTail>=rec.length){
                    return false;
                }else{
                    rec[recTail]=1;
                    recIndex = (++recTail)-1;
                }
            }else if(nums[i]!=nums[i-1]+1){
                for(int j=recHead;j<recTail;j++){
                    if(rec[j]<3){
                        return false;
                    }
                }
                return isPossible(Arrays.copyOfRange(nums,i,nums.length));
            }else if(recIndex==recTail-1){
                rec[recIndex--]++;
                if(recIndex<recHead)recIndex=recTail-1;
            }else{
                while(recHead!=recIndex+1){
                    if(rec[recHead]<3){
                        return false;
                    }
                    recHead++;
                }
                recIndex=recTail-1;
                rec[recIndex--]++;
                if(recIndex<recHead){
                    recIndex=recTail-1;
                }
            }
        }
        for(int j=recTail-1;j>=recHead;j--){
            if(rec[j]<3)return false;
        }
        return true;
    }
}
```
有意见欢迎评论交流呀！(๑•̀ㅂ•́)و
