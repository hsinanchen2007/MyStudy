### 解题思路
这道题当然可以用暴力解法来解，设两个指针就可以。
不过像这种求子序和的题，就很容易想到牛顿-莱布尼茨公式：
![a686c9177f3e670921a6bf643dc79f3df9dc5583.png](https://pic.leetcode-cn.com/23b26406e46f2d629ee52394e72e127f1b7edc0f2f5f6d66acf36d451361c384-a686c9177f3e670921a6bf643dc79f3df9dc5583.png)
也就是说：**求序列和可以和求序列差相互转化**
同样，在这里，我们可以通过构造原序列的积分序列，通过求积分序列的差来实现。
下面看推导过程：
![屏幕快照 2020-03-11 上午11.03.50.png](https://pic.leetcode-cn.com/079077569cecba91afa866fb2db70cb11ca6f617e4f13a83d8a4bae40a44cd9c-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-11%20%E4%B8%8A%E5%8D%8811.03.50.png)
最后执行结果：
![屏幕快照 2020-03-11 上午10.49.13.png](https://pic.leetcode-cn.com/75bbc3f8d63ec3ea4faaebc1e2f40708a448898cc3209ff7cfef586e3d561ff8-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-11%20%E4%B8%8A%E5%8D%8810.49.13.png)



当然代码还可以继续优化。
### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A) -> bool:
        '''
        '''
        # get the sum list
        SumA = []
        SumA.append(0)
        for i in range(len(A)):
            temp = SumA[i] + A[i]
            SumA.append(temp)
        
        print("Sum:  ",SumA)
        #judge
        L = len(A)
        if L < 3:
            return False

        F_i_plus_1 = SumA[L]/3
        F_j_plus_1 = F_i_plus_1*2
        print('F(i+1) %d , F(j+1) %d' %(F_i_plus_1,F_j_plus_1))

        if not F_i_plus_1 in SumA[1:L]:
            return False
        else:
            i_plus_1 = SumA[1:L].index(F_i_plus_1)+1
            print("i+1 %d" %i_plus_1)

        if not F_j_plus_1 in SumA[1:L]:
            return False
        else:
            temp_SumA = SumA[1:L][::-1]
            # print(temp_SumA)
            j_plus_1 = L-temp_SumA.index(F_j_plus_1)-1
            print("j+1 %d" %j_plus_1)

        if i_plus_1 >= j_plus_1:
            return False
        
        return True
```