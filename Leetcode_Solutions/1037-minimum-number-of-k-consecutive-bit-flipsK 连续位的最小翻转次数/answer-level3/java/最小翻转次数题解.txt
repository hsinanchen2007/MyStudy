### 解题思路
1. 先排除异常情况，A为空、K小于等于0、K比A的长度大，这些情况直接返回-1；
2. 从A的第一个元素开始，每碰到0就需要发生一次翻转，假设位置为a，则要把a~a+K-1的元素都翻转一次，直到把所有元素遍历完，如果数组里没有0元素满足条件，翻转次数则为最小翻转次数。
3. 每次翻转都把a~a+K-1的值都赋一遍执行时间较长，可能会不满足性能要求，可以优化一下：把每次翻转的最后一个元素位置记下来，跟当前要判断的元素位置比较一下，就知道当前位置的元素需要做几次翻转，直接计算出值比较即可，就不需要每次都真实翻转一次K子数组里的值了。

### 代码

```java
class Solution {
    public int minKBitFlips(int[] A, int K) {
        if (A == null || K <= 0) {
            return -1;
        }
        int len = A.length;
        int ret = 0;
        if (len < K) {
            return -1;
        }
        List<Integer> notEndIndexList = new ArrayList<Integer>();
        for (int i = 0; i < len; i++) {
            if (notEndIndexList.size() != 0 && notEndIndexList.get(0) < i) {
                notEndIndexList.remove(0);
            }
            int reverseNum = notEndIndexList.size() % 2;
            if (A[i] != 0 && A[i] != 1) {
                return -1;
            } else if (A[i] == (reverseNum ^ 1)) {
                continue;
            } else {
                if (i + K > len) {
                    return -1;
                }
                notEndIndexList.add(i + K - 1);
                ret = ret + 1;
            }
        }
        return ret;
    }
}
```