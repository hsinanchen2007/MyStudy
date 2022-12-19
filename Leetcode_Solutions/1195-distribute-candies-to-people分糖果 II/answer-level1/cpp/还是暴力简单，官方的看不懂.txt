### 解题思路
作者：yuexiwen
链接：https://leetcode-cn.com/problems/distribute-candies-to-people/solution/c-fu-za-du-candieskai-gen-hao-by-yuexiwen/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
这个也算是暴力了，循环里面就是重置小朋友的编号，条件语句算糖果数，最后一颗糖分给最后的小朋友。
### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int i = 1, j = 0;
        vector<int> result(num_people, 0);
        while (i*(i+1)/2 <= candies) {
            result[j++ % num_people] += i;
            i++;
        }
        i--;
        result[j % num_people] += candies - i*(i+1)/2;
        return result;
    }
};
```