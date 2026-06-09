// 根据官方题解，解法二基于快速排序的思想，能在O(n)的平均时间复杂度下完成目标，要优于基于排序的解法一，后者需要O(nlogn)的平均时间复杂度。

// 然而，考虑到具体实现，由于c++标准库中的sort是经过长时间打磨的，随便写一个解法二是很难战胜它的，我早期的解法二需要200ms的时间，而基于标准库sort的解法一只需要20ms，两者相差一个数量级😂

// 经过一个多小时的优化，下面的解法二才能勉强达到20ms的平均时间。感兴趣的读者可以比较两个代码的时间差异。在下面的解法二代码中，将mid的计算方式换成注释里的两行代码，即可得到解法一的实现。

// 人生三大错觉：

// 我比编译器聪明
// 我超越了标准库
// 我能管理好内存

// 😂

// ```
class Solution {
public:
    int find_kth_min(int buf[], int n, int k) {
        while (n > 1) {
            int pivot = buf[k / 2];
            swap(buf[k / 2], buf[n - 1]);
            
            int l = 0;
            while (1) {
                while (buf[l] < pivot)
                    l++;
                if (buf[l] > pivot || l == (n - 1))
                    break;
                l++;
            }
            if (l < n - 1) {
                for (int r = l + 1; 1; r++) {
                    if (buf[r] <= pivot) {
                        swap(buf[l], buf[r]);
                        l++;
                        if (r == n - 1)
                            break;
                    }
                }
                l--;
            }

            if (k == l) {
                return buf[k];
            } else if (k < l) {
                n = l;
            } else {
                buf += l + 1;
                n -= l + 1;
                k -= l + 1;
            }

        }
        return buf[0];
    }

    int minMoves2(vector<int>& nums) {
        if (nums.empty())
            return 0;

        int *buf = nums.data();
        int n = nums.size();

        int mid = find_kth_min(buf, n, n / 2);
        //sort(nums.begin(), nums.end());
        //int mid = nums[n / 2];
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += abs(buf[i] - mid);
        }

        return res;
    }
};
// ```