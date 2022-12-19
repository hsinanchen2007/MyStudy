### 解题思路
可以参考 最长递增子序列的解题思路 只需要先将身高和体重先进行排序 再通过二分进行处理

索引数组用来记录排序后的下标位置 其实直接用二维数组也可以 

### 代码

```java
class Solution {
    public int bestSeqAtIndex(int[] height, int[] weight) {
        if (height.length <= 1) {
            return height.length;
        }

        Integer[] indexs = new Integer[height.length];
        for (int i = 0; i < indexs.length; i++) {
            indexs[i] = i;
        }

        Arrays.sort(indexs, (o1, o2) -> {
            if (height[o1] == height[o2]) {
                return weight[o2] - weight[o1];
            }
            return height[o1] - height[o2];
        });
        
        int[] tail = new int[height.length + 1];
        int end = 0;
        tail[0] = weight[indexs[0]];
        for (int i = 1; i < height.length; i++) {
            if (weight[indexs[i]] > tail[end]) {
                ++end;
                tail[end] = weight[indexs[i]];
            } else {
                int left = 0;
                int right = end;
                int target = weight[indexs[i]];
                while (left < right) {
                    int mid = (left + right) >>> 1;
                    if (target > tail[mid]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                tail[left] = target;
            }
        }
        // 因为是从0 开始的 所以需要加1 
        end++;
        return end;
    }
}
```