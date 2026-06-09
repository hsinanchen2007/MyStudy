思路：
1、先考虑用一个数组A，将题目中提供的数组的第一位都保存进去。那么我们现在就可以得到一个区间范围，它的值是[A_min, A_max]. 
2、将数组A中最小值找到，将这个值替换成它所在数组的下一个值，这样我们就可以将A_min变大，就可能将区间缩小。当然这样做的时候，可能将A_max变大了，所以每次都需要重新检测A_min和A_max。当有其中的一个数组被遍历完的话，我们就可以找到最小区间。
3、因为每次遍历都需要从数组A中找最小值和它所属数组，所以我们可以建立一个结构体：值、值所属数组、值在所属数组的index。然后可以使用priority_queue来帮助我们完成寻找最小值的工作。

```
class Solution {
public:
    
    struct ele {
        int value;
        int index;
        int arrayIndex;
        ele(int v=0, int a=0, int i=0): value(v), arrayIndex(a), index(i) {}
    };

    struct CMP{
        bool operator()(const ele &a, const ele &b) const{
            return a.value > b.value;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
    
        priority_queue<ele, vector<ele>, CMP> que;
        int max = INT_MIN;
        long numsSize = nums.size();
        for (int i=0; i<numsSize; i++) {
            int v = nums[i][0];
            if (max < v) {
                max = v;
            }
            que.push(ele(v, i, 0));
        }

        int rl = -100005, rr = 100005;
        while (true) {
            ele e = que.top();
            que.pop();
            int arrayIndex = e.arrayIndex;
            int index = e.index;
            int l = e.value;
            int r = max;
            if (r - l < rr - rl) {
                rr = r;
                rl = l;
            }
            auto array = nums[arrayIndex];
            if (index >= array.size()) {
                break;
            }

            int v = array[index];
            if (max < v) {
                max = v;
            }
            que.push(ele(v, arrayIndex, index + 1));
        }
        return {rl, rr};
    }
};
```