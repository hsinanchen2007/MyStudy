解题思路：通过观察发现，其实每多做一道菜，相当于把已做过的菜的值再加一遍，因此这道题不需要用到乘法。
         只需要排序遍历累加，直到发现下一次将要加的值小于0为止，即为答案。
```
代码块
```
// C++
int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int valuesum = 0, favour = 0;
        for(int i = 0; i < satisfaction.size(); i++) {
            valuesum += satisfaction[i];
            if (valuesum > 0) {
                favour += valuesum;
            }
            else {
                break;
            }
        }
        return favour;
    }