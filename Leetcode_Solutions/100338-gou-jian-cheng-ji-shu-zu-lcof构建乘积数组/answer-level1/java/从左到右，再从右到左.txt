### 解题思路
第一轮循环，构建    【1, a1 , a1*a2 , a1*a2*a3 ... 】的数组
这个数组距离答案差的是每位需要分别乘上对应的数  【an*an-1*...a2, an*an-1*...a3, an*an-1*...4, ...】,
刚好是第一轮的操作去操作反过来的数组得到的结果
所以第二轮循环反过来

### 代码

```java
class Solution {
    public int[] constructArr(int[] a) {
        int left = 1;
        int right = 1;
        int[] ans = new int[a.length];
        for(int i=0;i<a.length;i++){
            ans[i] = left;
            left *= a[i];
        }
        for(int i=a.length-1;i>=0;i--){
            ans[i] *= right;
            right *= a[i];
        }
        return ans;
    }
}
```