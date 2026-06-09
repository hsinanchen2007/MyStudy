### [1338. 数组大小减半](https://leetcode-cn.com/problems/reduce-array-size-to-the-half/)

#### 题解

  + 统计数组元素大小的最大值作为统计元素出现频率数组的大小
  + 统计频率并排序
  + 频数从大到小累加到半或过半则停止
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int maxl = 0;
        for(int i = 0; i < arr.size(); i++)
            maxl = max(maxl, arr[i]);
        maxl++;
        int* cnt = new int[maxl];
        for(int i = 0; i < maxl; i++) cnt[i] = 0;
        for(int i = 0; i < arr.size(); i++)
            cnt[arr[i]] ++;
        sort(cnt, cnt+maxl);
        int ans = 0, sum = 0;
        for(int i = maxl-1; i >= 0; i--)
            if(cnt[i])
                {
                   ans++;
                   sum += cnt[i];
                   if(sum >= arr.size()/2)
                    break;
                }
        return ans;
    }
};
```