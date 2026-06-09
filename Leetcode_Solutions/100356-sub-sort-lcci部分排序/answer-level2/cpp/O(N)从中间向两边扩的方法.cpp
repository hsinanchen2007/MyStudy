### 解题思路
O（n） 先找到可能的最小区间，再向两边扩到真时的最小区间

### 代码

```cpp
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
            vector<int> res(2, -1);
            if(array.size() == 0)
                return res;
            int leftedge, rightedge, left, right;
            leftedge = 0;
            rightedge = array.size() - 1;
            while((leftedge < array.size() - 1) && (array[leftedge] <= array[leftedge+1]))
                ++leftedge;
            if(leftedge == array.size() - 1)
                    return res;
            while(rightedge > 0 && (array[rightedge] >= array[rightedge - 1]))
                --rightedge;
            left = leftedge == rightedge-1 ? leftedge-- : leftedge + 1;
            right = leftedge == rightedge-1 ? rightedge++ : rightedge - 1;
            int max = -9999999;
            int min = 9999999;
            for(int i = left;i<=right;++i)
            {
                max = max<array[i] ? array[i] : max;    
                min = min>array[i] ? array[i] : min;
            }
            while(!((leftedge<0||min>=array[leftedge]) && ((rightedge==array.size())||                          max<=array[rightedge])))
            {
                if((leftedge>=0) && (min<array[leftedge]))
                    {
                        max = max<array[leftedge] ? array[leftedge] : max;
                        leftedge--;
                        left--;
                    }
                if((rightedge<array.size()) && (max>array[rightedge]))
                    {
                        min = min > array[rightedge] ? array[rightedge] : min;
                        rightedge++;
                        right++;
                    }
            }
            res[0] = left;
            res[1] = right;
            return res;
    }
    
};
```