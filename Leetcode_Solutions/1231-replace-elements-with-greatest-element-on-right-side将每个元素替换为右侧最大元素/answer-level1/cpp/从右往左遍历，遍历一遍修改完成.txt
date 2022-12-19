### 解题思路
1.先将最后一个元素设为当前最大值
2.从倒数第二个元素开始遍历，首先先将当前元素保存到零时变量temp
3.将当前位置修改为当前最大值
4.比较如果temp大于当前保存的最大值，则修改当前最大值为tmmp
5.遍历完成为修改最后一个元素为-1

### 代码

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        int currMax = arr[len - 1];
        for (int i = len - 2; i >= 0; i--){
            int temp = arr[i];
            arr[i] = currMax;
            if (temp > currMax) currMax = temp;        
        }
        arr[len - 1] = -1;
        return arr;
    }
};
```