先上代码
```
class Solution(object):
    def threeSum(self,nums):
        return_list=[];i_point=0;j_point=0;last_nums_k='-big';last_nums_ipoint="-big";last_nums_jpoint="-big"
        nums.sort()
        for k in range (len(nums)):
            another_number=-nums[k]        
            if another_number>nums[len(nums)-1]+nums[len(nums)-2] or nums[k]==last_nums_k:
                #超过了最大的组合，所以不可能找到
                continue
            i_point=k+1
            j_point=len(nums)-1
            if nums[k]>0:
                break
            while(i_point<j_point):
                #[-1,0,1]
                if nums[i_point]!=last_nums_ipoint or nums[j_point]!= last_nums_jpoint:
                    if nums[i_point]+nums[j_point]<another_number:
                        i_point+=1
                    elif nums[i_point]+nums[j_point]>another_number:
                        j_point-=1
                    else:
                        return_list.append([nums[k],nums[i_point],nums[j_point]])
                        last_nums_ipoint=nums[i_point]#一定要放在这
                        last_nums_jpoint=nums[j_point]
                        i_point+=1
                        #j_point-=1

                else:
                    i_point+=1
                    j_point-=1

            last_nums_k=nums[k]
            last_nums_ipoint="-big"
            last_nums_jpoint="-big"


        return return_list
```
思路：
先排序之后依靠数学的技巧进行查找，这样就不需要判断加入的列表是否有重复的。
算法步骤：
1.对每一个`k`所指向的值取他的`another`，也就是 `target-nums[k]`, 也就是`-nums[k]`.
2.判断列表最后两个值是否小于`another`,是的话说明最大的两数和都没有，那么就不可能找到两数和等于`another`了，所以`continue`.
3.`i_point` 与 `j_point`指针用来做双指针滑动，值得注意的是`i_point`的初始值总在`k+1`的位置，这里就要有一个数学的基础了，可以自行证明.
4.进入`while`循环，`while`中是判断`i_point`与`j_point`分别指向的数字是否等于`another`，值得注意的是要比较`i_point`与`j_point`所指向的数字是否分别与上次相同:
如果都相同的话 让`i_point+1`,或者`j_point-1`，前面不要两个都执行，可以自行理解. 
如果不同的话就开始判断和大于`another`还是小于`another`，`i_point`往右移动会使得两数和变大，`j_point`往左移会使得两数和变小，这样调节的终止条件就是`i_point<j_point`，注意不能`i_point=j_point`，否则会使得两者有擦肩而过的可能性.
5.如步骤4所说，记录上次`i_point`,`j_point`所指向的值的时候要放在更新指针`i_point`或者`j_point`之前。

算法的重点我觉得就是步骤三了，好好体会。