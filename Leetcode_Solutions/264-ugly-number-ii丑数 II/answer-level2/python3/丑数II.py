### 解题思路
1. 假设现在有一个丑数的列表`ugly_number_list`，从小到大排列，大小为k；
2. 现在要找第k+1个丑数m；显然m是`ugly_number_list`中某一个数乘以2或乘以3或乘以5；
3. 令index1, index2, index3分别指向`ugly_number_list`中的三个数的下标，满足以下条件：
`ugly_number_list[index1]*2>ugly_number_list[-1], ugly_number_list[index1-1]*2<ugly_number_list[-1]`;
`ugly_number_list[index2]*3>ugly_number_list[-1], ugly_number_list[index2-1]*3<ugly_number_list[-1]`;
`ugly_number_list[index3]*5>ugly_number_list[-1], ugly_number_list[index3-1]*5<ugly_number_list[-1]`;

则第k+1个丑数m必然是`ugly_number_list[index1]*2, ugly_number_list[index2]*3, ugly_number_list[index3]*5`中的最小值min；将与min相对应的index(可能存在多个相等的min)都相应的加1；此时这些index仍满足第3步中的条件；继续找下一个丑数，直至找到第n个丑数；

### 代码

```python3
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_number_list = [1,2,3,4,5,6,8,9,10,12]
        if n <= 10:
            return ugly_number_list[n-1]
        count, index = 10, [6, 4, 2]
        while count < n:
            count += 1
            
            tmp1 = ugly_number_list[index[0]]*2
            tmp2 = ugly_number_list[index[1]]*3
            tmp3 = ugly_number_list[index[2]]*5
            
            min_tmp, label = tmp1, [0]
            if tmp2 < min_tmp:
                min_tmp, label = tmp2, [1]
            elif tmp2 == min_tmp:
                label.append(1)
            
            if tmp3 < min_tmp:
                min_tmp, label = tmp3, [2]
            elif tmp3 == min_tmp:
                label.append(2)
            
            ugly_number_list.append(min_tmp)
            for i in label:
                index[i] += 1

        return ugly_number_list[-1]
```