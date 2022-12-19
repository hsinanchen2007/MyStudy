写了三个小时了，大部分时候是逻辑的小细节问题。
一开始想到用空间换时间的o(n)方法，指针每次移动都会划出一个数组，然后添加数字到每个数组中，于是开心的超内存了。
之后老老实实的穷举o(n^2)，虽然优化到了n(n-1)/2，结果挡不住1000个元素轰炸而超时了。
思前想后优化了好久未果，看他人解题才有了o(n)的灵感。现在看来似乎就是官方的方法？

思路是三个指标，左中右。在右指针扫描时，用两个和数据规模一样的数组记录右指针到左中指针之间的不同数。
当右指针到达了不同数=K的场合时，让中指针跑到刚刚使得不同数=K-1的位置，中指针和左指针的差就是左右指针之间达标的子数组数量。
然后让右指针继续移动，反复执行就好了。
```
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int length = A.size();
        int total = 0;
        int *different = new int[length]();
        int *different_mid = new int[length]();
        int difAmount = 0;
        int difAmount_mid = 0;
        
        int left = 0;
        int middle = 0;
        int right = 0;
        while(right < length){
            if(different[A[right]-1] <= 0) difAmount += 1;
            different[A[right]-1]+= 1;
            if(different_mid[A[right]-1] <= 0) difAmount_mid += 1;
            different_mid[A[right]-1]+= 1;
            
            //让左指针跑到崩溃点。
            while(difAmount > K){
                different[A[left]-1] -= 1;
                if(different[A[left]-1] <= 0) difAmount -= 1;
                
                left += 1;
            }
            
            if(difAmount == K){
                //首先中指标移到崩溃点。
                while(middle <= right){
                    if(difAmount_mid > difAmount){
                        //要被左指标超过了，使劲走。
                        different_mid[A[middle]-1]-= 1;
                        if(different_mid[A[middle]-1] <= 0) difAmount_mid -= 1;
                    }else{
                        //要注意崩溃点的场合。
                        if(different_mid[A[middle]-1] > 1){
                            //不是崩溃点，接着走。
                            different_mid[A[middle]-1]-= 1;
                        }else{
                            //崩溃点，就看看不要动。
                            break;
                        }
                    }
                    middle += 1;
                }
                //左指标到中指标的差就是这一段中包含有的子数组。
                total += middle - left + 1;
            }
            
            //右指标继续扩展。
            right += 1;
        }
        
        return total;
    }
};
```

```
执行用时 : 64 ms, 在Subarrays with K Different Integers的C++提交中击败了100.00% 的用户
内存消耗 : 14 MB, 在Subarrays with K Different Integers的C++提交中击败了59.52% 的用户
```
结果有些夸张……100%什么的太夸张了，实际上提交了三次，另外两次是72ms,14.1MB和76ms,14.1MB。