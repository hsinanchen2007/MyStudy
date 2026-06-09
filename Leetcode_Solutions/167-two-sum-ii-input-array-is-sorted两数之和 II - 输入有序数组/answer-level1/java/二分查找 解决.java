### 解题思路
采用两个循环,第一个循环遍历 数组
第二个循环采用二分查找 
因此时间复杂度为 O(n*log(n))
重点在于二分法的应用
二分法第一步就是要确定查找区间,我这里采用左闭右开区间
也就是说初始化的时候 left = 0,right = numbers.length
这样一来 我的循环条件也就变成了 while(left < right>)
如果两个数之和大于目标值,则需要将右区间下移 这里因为右区间是开的,所以可以
让right = mid
反之, 则左区间上移,由于左区间是闭的,则
left = mid
当和=目标值
就说明找到了我们要找的值.return
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        //对每个数字进行一次循环
        //内循环进行二分查找
        
        for(int i=0; i<numbers.length; i++)
        {
            int left = i+1;
            int right = numbers.length; //半开半闭区间
            while(left<right)
            {
                int mid = left + (right -left)/2;
                int sum = numbers[mid] + numbers[i];
                if(sum == target)
                {
                    int a[] = new int[2];
                    a[0] = i+1;
                        a[1] = mid+1;
                    
                    return a;
                }
                else if(sum < target)
                {
                    left = mid+1;
                }
                else if(sum > target)
                {
                    right = mid;
                }
            }
        }
        return new int[2];
    }
}
```