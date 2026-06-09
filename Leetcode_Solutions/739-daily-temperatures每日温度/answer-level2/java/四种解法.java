# 分析
这道题本质上就是一道求右侧第一个比当前元素大的元素。只是这道题要的是索引的差值而已。

# 解法一 暴力
二重循环，第一重循环遍历每个数，第二重循环寻找当前数后面比当前数大的第一个元素，然后将两个下标相减即是答案。（这种解决是最符合直觉的，但是时间复杂度有点高）具体代码如下：
```java
 // 暴力二重循环，O(n*n)
    public int[] dailyTemperatures(int[] t) {
        int len = t.length;
        int[] ansArr = new int[len];

        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                if (t[j] > t[i]) {
                    ansArr[i] = j - i;
                    break;
                }
            }
        }

        return ansArr;
    }
```
**时间复杂度**：$O(n*n)$
**空间复杂度**(不考虑输出数组)：$O(1)$

# 解法二 记录索引+二分
从题目我们可知，温度的范围是$[30, 100]$，这个数字比较小，因此我们可以记录每个温度出现的索引列表。比如$[72,71,72]$,其中$72$的索引列表为$[0,2],71$的索引列表为$[1]$。然后，每当我们要求得右侧第一个比他大的元素的时候，假设当前索引为i，温度为$curT$，那么我们只要遍历$[curT+1, 100]$，求得比$curT$大的所有温度的第一个比i大的索引，然后取这些索引的最小值就是我们要的答案。其中，这里由于每个温度的索引列表是有序的，因此求第一个比i大的索引元素，可以是用二分。具体代码如下：
```java
private int binarySearchFirstBigger(List<Integer> indexList, int target) {
        int low = 0;
        int high = indexList.size() - 1;
        while (low <= high) {
            int mid = (low + high) >>> 1;
            int midVal = indexList.get(mid);

            if (target < midVal) {
                if (mid == 0 || indexList.get(mid - 1) < target) {
                    return midVal;
                }

                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }

    // 二分
    public int[] dailyTemperatures(int[] tArr) {
        int len = tArr.length;
        int[] ansArr = new int[len];
        List<Integer>[] indexListArr = new ArrayList[101];

        for (int i = 0; i < len; i++) {
            int t = tArr[i];
            if (indexListArr[t] == null) {
                indexListArr[t] = new ArrayList<>();
            }
            indexListArr[t].add(i);
        }

        for (int i = 0; i < len; i++) {
            int curT = tArr[i];
            int minIndex = Integer.MAX_VALUE;
            for (int j = curT + 1; j <= 100; j++) {
                if (indexListArr[j] == null) {
                    continue;
                }

                // 二分查找第一个比i大的索引，然后所有[curT+1, 100]中求得的这个索引取最小值即是答案（右侧第一个温度比当天大的元素）
                int nextIndex = binarySearchFirstBigger(indexListArr[j], i);
                if (nextIndex != -1) {
                    if (nextIndex < minIndex) {
                        minIndex = nextIndex;
                    }
                }
            }

            if (minIndex != Integer.MAX_VALUE) {
                ansArr[i] = minIndex - i;
            }
        }

        return ansArr;
    }
```
**时间复杂度**：$O(n*70*log(n/70))$ 约等于 $O(n*log(n))$
**空间复杂度**(不考虑输出数组)：$O(n)$

# 解法三 单调栈
逆序遍历，维护一个单调递减栈（从栈底到栈顶），然后每次遍历的右侧第一个比他大的元素就是栈顶的元素。具体代码如下：
```java
 // 单调栈
    public int[] dailyTemperatures(int[] tArr) {
        int len = tArr.length;
        int[] ansArr = new int[len];
        int[] stack = new int[len];  // 存在索引
        int top = -1;

        for (int i = len - 1; i >= 0; i--) {
            int curT = tArr[i];
            while (top >= 0 && curT >= tArr[stack[top]]) {
                top--;
            }

            stack[++top] = i;
            ansArr[i] = top == 0 ? 0 : stack[top-1] - i;
        }

        return ansArr;
    }
```
**时间复杂度**：$O(n)$  
**空间复杂度**(不考虑输出数组)：$O(n)$
说明，虽然看起来是有二重循环，但是每个元素最多进栈和出栈各一次，最坏情况就是数组是逆序的情况，这时候也就是$O(2*n) = O(n)$。

# 解法四 逆序+跳跃
依然逆序遍历，但是每次的结果利用到了右侧已经计算的结果，这样可以加快遍历速度。如题目中的数组$[73, 74, 75, 71, 69, 72, 76, 73]$,
当我们要计算75元素右侧第一个比他大的元素的时候，由于我们逆序遍历，已经计算了71元素的右侧第一个比他大的元素是76，因此我们可以跳过69，72，直接将76与75比较即可。具体代码如下：
```java
// 逆序遍历，利用已经计算的结果，通过跳跃，减少重复计算
    public int[] dailyTemperatures(int[] tArr) {
        int len = tArr.length;
        int[] ansArr = new int[len];
        ansArr[len - 1] = 0;

        for (int i = len - 2; i >= 0; i--) {
            if (tArr[i] < tArr[i+1]) {
                ansArr[i] = 1;
                continue;
            }

            int rightIndex = i + 1 + ansArr[i+1];
            while (ansArr[rightIndex] != 0 && tArr[rightIndex] <= tArr[i]) {
                rightIndex += ansArr[rightIndex];
            }

            ansArr[i] = tArr[rightIndex] > tArr[i] ? rightIndex - i : 0;
        }

        return ansArr;
    }
```
**时间复杂度**：$O(n*70) = O(n)$
**空间复杂度**(不考虑输出数组)：$O(1)$
