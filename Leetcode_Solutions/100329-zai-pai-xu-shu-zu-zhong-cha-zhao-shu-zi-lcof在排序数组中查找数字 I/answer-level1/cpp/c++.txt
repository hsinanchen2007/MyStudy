采取二分查找的方式查找上下界
注意：
因为在 left 与 right 仅相差 1 的情况下
mid = (left + right)/2 = left
如果想找右边界，应该最终使mid = right要给左右之和+1
1.寻找左边界mid = (left + right)/2
保证最终right = mid赋值后 能够使 right == left 
2.寻找右边界mid = (left + right + 1)/2
保证最终left == mid赋值后 能够使 right == left

