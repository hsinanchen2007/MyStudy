# 解法1：排序+二分搜索
1. 从大到小降序排序(快速排序)，时间复杂度O(NlogN)
2. 二分搜索，结束条件：找到一个元素citations[i]，满足citations[i]>=(i+1) && citations[i+1]< (i+2), 时间复杂度O(N)
综合下来，
时间复杂度：O(NlogN+N)
空间复杂度：O(1)

执行用时：8ms
内存消耗：9.3MB

```
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        if (citations.size() == 0) {
            return 0;
        }

        int ans = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        int left = 0;
        int right = citations.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] < (mid + 1)) {
                right = mid - 1;
            } else {
                if ((mid + 1) < citations.size() && citations[mid + 1] < (mid + 2)) {
                    ans = mid + 1;
                    break;
                }
                left = mid + 1;
            }
        }

        if (left >= right && citations[left] >= (left + 1)) {
            ans = left + 1;
        }

        return ans;
    }
};
```



# 解法2：优先队列
1. 解法1耗时在排序上，但根据题意，我们其实并不关心元素的次序，根据元素和其下标的关系，可以将元素分成前后两部分，前面H个元素满足citations[i]>=(i+1)，剩余N-H个元素满足citations[i]<(i+1); 因此，可以考虑使用优先队列（大顶堆）不断考察队顶元素和其下标的关系
2. 如果队顶元素满足citations[i]>=(i+1)，则将队顶元素移除，继续考察下一个队顶元素，直到该条件不满足，则找到了H
综合下来，
时间复杂度，构造函数O(N), pop O（logN）, top O(1)
空间复杂度，需要一个额外的队列，O(N)

执行用时 0ms

```
class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        if (citations.size() == 0) {
            return 0;
        }

        int ans = 0;
        priority_queue<int> pq(citations.begin(), citations.end());
        while (pq.empty() == false) {
            if (pq.top() >= (ans + 1)) {
                ans++;
                pq.pop();
            } else {
                break;
            }
        }

        return ans;
    }
};
```
