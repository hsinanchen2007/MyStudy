### 解题思路
滑动窗口
滑动窗口的大小为所有1的个数windows，在滑动窗口内含有最多的1的个数maxvalue；
结果answer = windows - maxvalue;

### 代码

```cpp
class Solution {
public:
    int minSwaps(vector<int> &data)
    {
        int windowsize = 0;

        for (int i = 0; i < data.size(); i++) {
            if (data[i] == 1) {
                windowsize++;
            }
        }

        int begin = 0;
        int maxvalue = 0;
        int count = 0;

        for (int i = 0; i < data.size(); i++) {
            if (i < windowsize) {
                count += data[i];
            } else {
                count = count - data[begin] + data[i];
                begin++;
            }

            maxvalue = max(maxvalue, count);
        }

        int result = windowsize - maxvalue;
        return result;
    }
};
```