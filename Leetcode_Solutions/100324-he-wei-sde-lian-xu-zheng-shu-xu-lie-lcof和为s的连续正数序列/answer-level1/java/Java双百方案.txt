### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/a403108ddd5080951338568a2f63c71842f99721a8e1f64a06a0ff00c8f73d0f-%E6%8D%95%E8%8E%B7.PNG)


以9，[2,3,4]为例，考虑数组最中间的数3，则9 = 3 * 数组长度。当然数组长度为偶数时中间的值为×.5（比如[4,5]为4.5），于是我将所有数同时乘以2，即9变18，[2,3,4]变[4,6,8]。数组长度n满足n*(n+1) = 18，故n<sqrt(18)。于是开始遍历数组长度，18除以从2到sqrt(18)，当长度为偶数时，商必须为奇数，当长度为奇数时，商无所谓。
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        if (target < 3){
            return new int[0][0];
        } else{
            int d = target * 2;
            int circle = (int) Math.sqrt(d);
            List<int[]> l = new ArrayList();
            for (int i = 2; i <= circle; i++){
                if (d % i == 0){
                    int j = d / i;
                    int[] temp = new int[i];
                    if ((i % 2 == 0 && j % 2 != 0) || i % 2 != 0){
                        for (int k = 0; k < i; k++){
                            temp[k] = (j + 1 - i + k * 2) / 2;
                        }
                        l.add(0,temp);
                    }
                }
            }
            if (l.size() == 0){
                return new int[0][0];
            } else{
                int[][] res = new int[l.size()][];
                for (int i = 0; i < l.size(); i++){
                    res[i] = l.get(i);
                }
                return res;
            }
        }
    }
}
```