![接雨水Leetcode提交.png](https://pic.leetcode-cn.com/42439a3a9f4a34c37196ce02a1226ee31a95e4bca9d7fb3dbc5d6ea07635517c-%E6%8E%A5%E9%9B%A8%E6%B0%B4Leetcode%E6%8F%90%E4%BA%A4.png)


贴下代码留个纪念
`class Solution(object):
    def QuickSort(self,alist, start, end):
        '''快速排序'''
        # 建立递归终止条件
        if start >= end:
            return
 
        # low为序列左边要移动的游标
        low = start
        # last为序列右边要移动的游标
        last = end
 
        # 将起始元素设为要寻找位置的基准元素
        mid_num = alist[start]
 
        while low < last:
        # 当low与last未重合，并且比基准元素要大，就将游标向左移动
            while low < last and alist[last] >= mid_num:
                last -= 1
        # 如果比基准元素小，就跳出循环，并且把其放在基准元素左边
            alist[low] = alist[last]
 
        # 当low与last未重合，并且比基准元素要小，就将游标向右移动
            while low < last and alist[low] < mid_num:
                low += 1
        # 如果比基准元素大，就跳出循环，并且把其放在基准元素右边
            alist[last] = alist[low]
 
        # 当low与last相等，就是mid_num的排序位置
        alist[low] = mid_num
        self.QuickSort(alist, start, low-1) # 对左边的序列进行递归
        self.QuickSort(alist, low+1, end)

    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        def max_index(array):
            """
            :type array:List[int]
            :rtype:int
            """
            return array.index(max(array))
        
        def sum_height(array):
            """求总高度"""
            sm=0
            for height in array:
                sm+=height
            return sm
        if height == []:
            return 0
        n=len(height)#记录总长
        x_max_index=[]#创建列表存放最值元素的下标
        water_sum=0#定义盛水总量
        
        x_max_index.append(max_index(height))#将最大值的下标放入列表
        mx=x_max_index[0]+1#最大值右边开始循环的起始下标
        
        i=0
        while 0 not in x_max_index:
            height_sub=height[:x_max_index[i]]
            x_max_index.append(max_index(height_sub))
            i+=1
        #最值左边开始循环，不断将次大值的下标存入最值下标列表，直到首位元素被存入
        
        if n-1 not in x_max_index:
            height_sub=height[mx:]
            x_max_index.append(max_index(height_sub)+mx)
            #将右侧最大值的下标存入最值列表
        
        m=len(x_max_index)-1

        while n-1 not in x_max_index:
            mx_sub=x_max_index[m]+1
            height_sub=height[mx_sub:]
            x_max_index.append(max_index(height_sub)+mx_sub)
            m+=1

        n_sub=len(x_max_index)-1
        self.QuickSort(x_max_index,0,n_sub)

        for k in range(1,n_sub+1):
            l_index,r_index=x_max_index[k-1],x_max_index[k]
            
            if height[l_index] <= height[r_index]:
                water_sum+=height[l_index]*(r_index-l_index-1)
                water_sum-=sum_height(height[l_index+1:r_index])
            else:
                water_sum+=height[r_index]*(r_index-l_index-1)
                water_sum-=sum_height(height[l_index+1:r_index])
        
        return water_sum`