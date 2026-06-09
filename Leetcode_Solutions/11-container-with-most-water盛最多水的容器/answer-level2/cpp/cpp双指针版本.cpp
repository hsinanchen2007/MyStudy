```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
    int max_area = 0;
    int i = 0, j = height.size() - 1;
    while (i < j){
      int tmp_area = (j-i)* (height[i] < height[j] ? height[i] : height[j]);
      if (height[i] < height[j])
        i++;
      else
        j--;
      max_area = tmp_area > max_area ?tmp_area:max_area;
    }
    return max_area;
    }
};

```
![Screenshot from 2019-09-29 15-45-32.png](https://pic.leetcode-cn.com/d2c4acccbc86b089b2a403a57050eb2626a1361101e1883d01890b8270366aa5-Screenshot%20from%202019-09-29%2015-45-32.png)
