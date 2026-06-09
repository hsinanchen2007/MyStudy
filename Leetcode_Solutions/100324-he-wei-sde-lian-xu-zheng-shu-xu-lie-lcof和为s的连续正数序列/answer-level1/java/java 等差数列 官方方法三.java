### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> list = new ArrayList<>();
        for(int l = 1,r=2; l<r; ){ // 双指针，因为必须由两个数组成，所以l从1开始，r从2开始
            int res = (l + r) * ( r - l + 1) /2;     //等差数列公式 =   (a1+aN)*(N)/2
            if ( res == target){       //当相等时加入结果
                int[] tmp = new int[r-l+1];
                int k = 0;
                for (int i = l; i <= r; i++){
                    tmp[k++] = i;
                }
                list.add(tmp);
                l++;    //此时左边这个点已经计算过了 应该往右移了
            }else if (res < target){ // 若小于目标值， 将右指针往右移动
                r++;
            }else if (res > target){ //大于目标值， 左指针往右移动
                l++;
            }
        }
        return list.toArray(new int[list.size()][]);
    }
}
```