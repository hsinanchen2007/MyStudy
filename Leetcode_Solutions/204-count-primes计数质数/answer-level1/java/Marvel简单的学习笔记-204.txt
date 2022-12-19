### 埃氏筛法求素数
枚举给定范围内的所有数，对于每一个素数，它的所有倍数均不是素数，全部筛出，最后剩下未被筛除的数都是素数。
可以用一个boolean[]数组记录是否被筛除，true为被筛除，false未被筛除。除此之外，假设一开始所有数都是素数，即均为被筛除，从2开始循环上述埃氏筛法的操作，可得到范围内的所有素数及其数量。
### 代码

```java
class Solution {
    public int countPrimes(int n) {
        boolean[] isRemove = new boolean[n];
        int cnt=0;
        for(int i=2; i<n; i++)
        {
            if(!isRemove[i])
            {
                cnt++;
                if(i>n/i)   continue;//超出了数组范围，则该素数的倍数无需继续筛除
                for(int j=i*i; j<n; j += i)
                    if(!isRemove[j])    isRemove[j]=true;
            }
        }
        return cnt;
    }
}
```