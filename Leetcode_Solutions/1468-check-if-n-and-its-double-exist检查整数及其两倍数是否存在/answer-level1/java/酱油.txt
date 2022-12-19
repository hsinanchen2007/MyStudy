### 解题思路 哈希表 这个目前是100% 和 100%
先排序
eg: -10 -9 -8 0 0 8 9 16 
然后直接往set里面添 如果-9可以 那么一定能在hash表里面找到 -16 因为是从小到大排的序
同理 如果16能找到 那么一定能找到8 注意一定要是偶数 奇数就不用了
还有一个特殊的0 先判断后添加是为了处理 0

### 代码

```java
class Solution {
    public boolean checkIfExist(int[] arr) {
        if (arr.length < 2) {return false;}
        HashSet<Integer> all = new HashSet<>(arr.length, 1.0f);
        Arrays.sort(arr);
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] <= 0) {
                if (all.contains(arr[i]<<1)) {
                    return true;
                }
                all.add(arr[i]);
            } else {
                if ((arr[i] & 1) == 0 && all.contains(arr[i]>>1)) {
                    return true;
                }
                all.add(arr[i]);
            }
        }
        return false;
    }
}
```
### 解题思路 二分法
先排序
eg: -10 -9 -8 0 0 8 9 16
嗯 .... 我不想写了

### 代码 不是正确的 但是如果读懂了 就能懂思想了
public boolean checkIfExist(int[] arr) {
        if (arr.length < 2) {return false;}
        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));
        for (int j = arr.length-1; j >= 1; j--) {
            int i = j>>1;
            if (arr[j] >= 0) {
                if ((arr[j] & 1) == 1) { continue; }
                while (i < j) {
                    if (arr[i] < 0) {
                        i = (i+j)>>1;
                        continue;
                    }
                    int half = arr[j]>>1;
                    if (arr[i] == half) {
                        return true;
                    } else if (arr[i] < half) {
                        i = (i+j)>>1;
                    } else {
                        i = (i+j)<<1;
                    }
                }
            } else {
                while (i >= 0) {
                    if ((arr[i] & 1) == 0 && arr[i]>>1 == arr[j]) {
                        return true;
                    }
                    i--;
                }
            }
        }
        return false;
    }