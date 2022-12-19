### 解题思路
先看一种简单的情况，假如数组中无重复元素，此时这道题的思路如下：
1. 对于每个新元素，在已存在的组合中依次加入这个新元素组成新的组合，注意这里已存在的组合不变
2. 将(1)中的新组合加入到原来的已存在组合中

对于本题，数组中有重复的元素，对于后出现的重复的元素不能直接拷贝原来已存在的组合，这样会引入重复。通过归纳推理找到规律：对于后来的重复元素，只需要拷贝原来已存在的组合中此重复数等于重复次数的组合，所以需要一个变量equCnt记录重复次数。

算法思路：
1. 对原数组进行排序
2. 将nums中第一个数据直接加入到res中
3. 从索引1开始遍历nums
4. 对于重复的数据，需要拷贝res的元素中(是一个数组)重复数的个数大于已重复的个数，举个例子：res[0]=[1,2],res[1]=[1,2,2],此时equCnt=2，此时只拷贝res[1],显然拷贝res[0]会引入重复。
5. 对于不重复的数据，直接拷贝res中的数组
6. 对拷贝出的二维数组temp，每个元素都加入这个新值
7. 将temp得出的新组合加入到res中
### 代码

```golang
func subsetsWithDup(nums []int) [][]int {
   res:=[][]int{}
   if len(nums)<=0{
       return res
   }
    sort.Ints(nums)
    equCnt:=1
    res=append(res,[]int{})
    res=append(res,[]int{nums[0]})

   for i:=1;i<len(nums);i++{
       temp:=[][]int{}
        
       if nums[i]==nums[i-1]{
           for _,v:=range res{
               if numInSlice(v,nums[i])>=equCnt{
                    cur:=[]int{}
                    cur=append(cur,v...)
                    temp=append(temp,cur)
               }
           }
           equCnt++
       }else{
           for _,v:=range res{
               cur:=[]int{}
               cur=append(cur,v...)
               temp=append(temp,cur)
           }
           equCnt=1
       } 

       for j:=0;j<len(temp);j++{
           temp[j]=append(temp[j],nums[i])
           res=append(res,append([]int{},temp[j]...))
       }    
   }

   return res 
}

func numInSlice(v []int,t int) (r int){
    for i:=len(v)-1;i>=0;i--{
        if v[i]!=t{
            break
        }

        r++
    }
    return 
}
```