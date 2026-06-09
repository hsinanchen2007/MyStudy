        n = len(nums)
        if n <= 1:
            ret = nums[0]       
        ret = {"max":nums[0],"sum":nums[0]}
        for i in range(1,n):
            if ret['sum'] + nums[i] > nums[i]:    
                ret['sum'] += nums[i] 
            else:
                ret['sum'] = nums[i] 

            if ret['max'] < ret['sum']:
                ret['max'] = ret['sum']
            
        return ret['max']
如下图，内存消耗最少，由于字典消耗的是确定位置的2个内存单元，不像临时变量不停的变化堆栈吗？

![image.png](https://pic.leetcode-cn.com/09c847a9438156cc1fa140da88ff6ae8f4808b1c52db5be26b05bed5b4e46117-image.png)




