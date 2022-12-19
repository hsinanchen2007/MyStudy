这题用贪心思路很简单：对于每个 B[i] ，挑选最小的大于它的 A[j] , 因此可以无脑二重循环，复杂度 O(n^2)。写起来也很简单。

然而我想着怎么优化一下，显然可以排序B，如果当前已经没有 A[A.length - 1] > B[i]，那么后面就不用扫了。复杂度 O(nlogn)。这个思路想起来也简单，但写起来却不那么好写，调了我很长时间，代码如下，希望能帮到大家。

```java
class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        List<int[]> arr = new ArrayList();
        int n = A.length;
        int[] res = new int[n];
        for (int i = 0; i < n; i ++) arr.add(new int[]{B[i], i}); // 我们要把 B 的位置也存起来
        Collections.sort(arr, (o1, o2) ->o1[0] - o2[0]);
        Arrays.sort(A);
        Arrays.fill(res, -1);
        int[] memo = new int[n];

        int idx = 0;
        for (int i = 0; i < n; i ++)
        {
            while (idx < n && A[idx] <= arr.get(i)[0]) idx ++; // 找到第一个大于 B[i] 的 A[idx]
            if (idx == n) break; // 找完了 A 直接退出
            if (memo[idx] == 0) 
            {
                res[arr.get(i)[1]] = A[idx];
                memo[idx] = 1;
            }
            idx ++;
        }

// 这里把不存在大于 B[i] 的 A[idx] 放入 res，memo[t] == 1 是前面用过的 A[idx]，跳过
        int t = 0;
        for (int i = 0; i < n; i ++)  
        {
            if (res[i] == -1) 
            {
                while (memo[t] == 1) t ++;
                res[i] = A[t];
                memo[t] = 1;
            }
        } 
        return res;
    }
}
```