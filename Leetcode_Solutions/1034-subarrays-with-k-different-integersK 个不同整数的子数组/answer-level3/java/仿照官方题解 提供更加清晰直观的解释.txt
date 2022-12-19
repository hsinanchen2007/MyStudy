#    Brute Force
谁都会解决啦~ O(n^2) 但是会超时，很难受。
    
# 小trick
    [1,2,1]中以window[right]结尾的子数组还有[2,1]
    [1,2,1,2]中以window[right]结尾的子数组还有[2,1,2],[1,2]
    注意，不能直接right - left
    请看这个例子：
        输入：A = [2,2,1,2,2,2,5], K = 2
        如果这时候，window为[2,2,1,2,2],以window[right]结尾的子数组[2,2]是不符合要求的。
    
# **必须维护两个滑动窗口**
    window1区间: (left1, right), 需要满足window1恰好有K个不同整数。
    window2区间: (left2, right), 需要满足window2恰好有K-1个不同整数。
    这样就能保证：[left1, left2]这个区间中，以left2为结尾的子数组都能满足恰好有K个不同整数。
    还是这个例子：
    大window[2,2,1,2,2],
    window1[2,2,1,2,2], left1 = 0, right = 4,
    window2[2,2], left2 = 3, right = 4
    以window[left2]结尾的并且符合要求的子数组：
    [2,2,1,2,2], [2,1,2,2], [1,2,2] 此时就是left2-left1=3



```
class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        Window window1 = new Window();
        Window window2 = new Window();
        int ans = 0, left1 = 0, left2 = 0;
        for (int right = 0; right < A.length; right++) {
            int x = A[right];
            window1.add(x);
            window2.add(x);            
            // 让window1左指针移动,直到等于K
            while (window1.different() > K) {
                window1.remove(A[left1]);
                left1++;
            }
            // 让window2左指针移动,直到恰好小于K
            while (window2.different() >= K) {
                window2.remove(A[left2]);
                left2++;
            }
            // window2恰好少一个，window1恰好等于K
            // 这时所有以left2为结尾的子数组，都是符合要求的            
            ans += left2 - left1;
        }
        return ans;
    }
}

class Window {
    Map<Integer, Integer> count;
    int nonzero;
    
    Window() {
        count = new HashMap();
        nonzero = 0;
    }
    
    void add(int x) {
        count.put(x, count.getOrDefault(x, 0) + 1);
        if (count.get(x) == 1)
            nonzero++;
    }
    
    void remove(int x) {
        count.put(x, count.get(x) - 1);
        if (count.get(x) == 0)
            nonzero--;
    }
    
    int different() {
        return nonzero;
    }
}
```

