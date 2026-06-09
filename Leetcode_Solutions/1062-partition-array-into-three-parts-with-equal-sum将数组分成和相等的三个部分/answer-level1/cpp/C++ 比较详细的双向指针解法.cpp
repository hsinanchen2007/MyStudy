### 解题思路
这道题思路其实是很清晰的，求总和再求均值，可以去遍历一遍数组，然后如果前i个总和等于sum/3，后k个总和等于sum/3并且中间还有元素，这样就可以返回true了，其中需要注意的特殊情况有
[1,-1,1,-1]类似的，前两个和为0，后两个和为0，看似可以，但是其实不可以，因为只有两组
我写的代码可能有些繁琐，但是基本思想应该都体现出来了。
### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0, sum1, sum2, flag1, flag2;
        if(A.size() == 0)
            return false;
        for(int i = 0; i < A.size(); i ++)
            sum += A[i];
        if(sum % 3 != 0)
            return false;
        sum1 = A[0], sum2 = A[A.size() - 1];
        flag1 = 0, flag2 = A.size() - 1;
        for(int i = 1; i < A.size() - 1; i ++){
            if(sum1 != sum/3){
                sum1 += A[i];
                if(sum1 == sum/3)
                    flag1 = i;
            }
            if(sum2 != sum/3){
                sum2 += A[A.size() - i - 1];
                if(sum2 == sum/3)
                    flag2 = A.size() - i - 1;
            }
            if(sum1 == sum/3 && sum2 == sum/3 && flag2 > flag1 + 1){
               return true;
            }
        }   
        return false;
    }
};
```
![image.png](https://pic.leetcode-cn.com/eaa9f8dce962c371db3ceebf02a0d2ece7eea03c40095b51b355e3a22baf33c7-image.png)

