### 解题思路
本题是荷兰国旗问题，采用三个指针p0:0的右边界;p2:2的左边界;cur:用于遍历的指针。当cur为0时与p0交换，当cur为2时与p2交换，同时都要调整对应指针位置
算法思路：
1. 初始化p0,p2的位置，p0=0，p2=len(nums)-1
2. cur开始遍历
3. 如果nums[cur]==0,交换cur与p0，同时p0加1
4. 如果nums[cur]==1,cur加1
5. 如果nums[cur]==2，交换cur与p2，同时p2减1
6. 每次遍历要保证cur位置不能低于p0，目的是保证交换0时也向前加1

### 代码

```golang
func sortColors(nums []int)  {
    if len(nums)==0{
        return
    }
    //1 初始化三个指针
    p0:=0
    p2:=len(nums)-1
    cur:=0
    //2 cur开始遍历
    for cur<=p2{
        if nums[cur]==0{ //3 cur位置与p0位置交换
            nums[cur]=nums[p0]
            nums[p0]=0
            p0++
        }else if nums[cur]==1{//4 cur加1
            cur++
        }else if nums[cur]==2{ //5 cur与p2位置交换
            nums[cur]=nums[p2]
            nums[p2]=2
            p2--
        }
        //6 调整cur指针位置
        if cur<p0{      
            cur=p0
        }
    }
}
```