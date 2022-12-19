### 解题思路
此处撰写解题思路
主要是找到能计算的值
1、从左到右依次遍历，有两种情况
2、以当前点为基准，找到后面比他大且距离它最近的位置，然后计算面积；若找不到，则进行第三步
3、以当前点为基准，找到后面比他次小且距离它最远的位置，然后计算面积
4、更新脚标，继续扫描

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        // 从左到右依次遍历
        int i = 0;
        int sum = 0;
        while (i < height.size()) {
            if (height[i] == 0) {
                i++;
                continue;
            }

            int index = FindNext(height, i);  // 找下一个比当前值高的最近的一个值

            if (index == -1 ) {
                index = FindNextMax(height, i);  // 找下一个比当前值小的最大值，且是最后一个 
            }

            if (index == -1) {
                break;
            }

            sum += GetSum(height, i, index);
            if (index == height.size() - 1) { // 已搜索完毕，直接返回sum ，否则后面更新循环变量会进入死循环
                return  sum;
            }
            //cout << "sum = " << sum << "  i = " << i << " index = " << index << endl;
            i = index; // 循环变量更新放在最后
        }

        return sum;
    }
    
    int GetSum(vector<int>& height, int start, int end)
    {
        int sum = 0;
        int i = 0;
        if (height[start] < height[end]) {
            i = start;
        } else {
            i = start + 1;
        }
        for (; i < end; i++) {
            sum += height[i];
        }

        int area = 0;
        if (height[start] < height[end]) {
            area = (end - start) * height[start] - sum;
        } else {
            area = (end - start - 1) * height[end] - sum;
        }
        
        return area >= 0 ? area : 0; // 计算值可能出现负数
    }

    int FindNext(vector<int>& height, int pos) 
    {
        int index = -1;
        
        for (int i = pos + 1; i < height.size(); i++) {
            if (height[i] > height[pos]) {
                index = i;
                return index;
            }

            if (height[i] == height[pos]) {
                index = i;
            }
        }

        return index;
    }

    int FindNextMax(vector<int>& height, int pos) 
    {
        int maxNum = -1;
        int index = 0;
        for (int i = pos + 1; i < height.size(); i++) {   
            if (maxNum <= height[i]) {
                maxNum = height[i];
                index = i;
            }  
        }

        return index;
    }

};
```