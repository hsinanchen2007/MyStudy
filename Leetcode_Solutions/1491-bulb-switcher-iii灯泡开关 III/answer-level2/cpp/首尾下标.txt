### 解题思路
![TIM截图20200308131514.jpg](https://pic.leetcode-cn.com/9932859389acc694dad3054c8064404d9c2b73b7936c262b577216794dfa325f-TIM%E6%88%AA%E5%9B%BE20200308131514.jpg)

在周赛的时候只想到用简单朴素的方法做，结果超时。（当时做第三题也是因为超时用了一个多小时）
吃完饭在纸上画了画，发现其实挺简单的。就是用两个下标（first,last记录亮着的灯泡的开始和结束）。
当first到last都亮着且first是0号开始的时候，才能符合条件。

### 代码

```cpp
class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int count = 0;
		int first =light.size(),last = -1;
		for (int i = 0; i < light.size(); i++) {
			first = (first < light[i]-1) ? first : light[i]-1;
			last = (last > light[i]-1) ? last : light[i]-1;
			if (last - first == i && last == i) { // first到last都亮着，且first==0
				count++;
			}
		}
		return count;
	}
};
```