## 前后交换


![iamge](https://pic.leetcode-cn.com/63b48e2be362223395c53e1689de42936687a4e44b2f4eefab7d6aa3d56436af.png)



### 思路

- 标签：`前后双指针`、`前后交换`
- 将后面的偶数跟前面的奇数交换
- 为了减少需要考虑的条件：因为题目提示可以不考虑结果顺序，所有只要前面的数不是偶数就可以交换，不一定要后面也是偶数
- 时间复杂度：O(n)
- 空间复杂度：O(1)

### 代码

```Java []
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int left = 0;
        int right = A.length - 1;
        while (left < right) {
            if (A[left] % 2 == 0) {
                left++;
            } else {
                int tmp = A[left];
                A[left] = A[right];
                A[right] = tmp;
                right--;
            }
        }
        return A;
    }
}
```

```Python []
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        front = 0
        end = len(A) -1 
        while front < end:
            if A[front] % 2 == 0:
                front += 1
            else:
                tmp = A[end]
                A[end] = A[front]
                A[front] = tmp
                end -= 1
        return A
```

```JS []
var sortArrayByParity = function(A) {
    var left = 0;
    var right = A.length - 1;
    while (left < right) {
        if (A[left] % 2 == 0) {
            left++;
        } else {
            var tmp = A[right];
            A[right] = A[left];
            A[left] = tmp;
            tmp--;
        }
    }
    return A;
};
```



