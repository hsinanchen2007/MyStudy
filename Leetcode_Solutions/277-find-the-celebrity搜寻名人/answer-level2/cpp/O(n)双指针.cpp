解法主要参考了题解中的某一位，思想非常巧妙。
名人的定义是 其余人都认识他，他只认识自己。
通过双指针left=0 和 right=n-1， 如果left knows right, left必然不是名人,left++;反之亦然, right--。
```cpp
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
private:
public:
    int findCelebrity(int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            if (knows(left, right)) left ++;
            else
                right --;
        }
        for (int i = 0; i < n; i ++) {
            if (i != left && (!knows(i, left) || knows(left, i)))
                return -1;
        }
        return left;
    }
};
```