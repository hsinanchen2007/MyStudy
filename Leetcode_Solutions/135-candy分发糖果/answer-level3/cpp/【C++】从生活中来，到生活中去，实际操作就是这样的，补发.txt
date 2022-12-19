1.先从头到尾发一遍，先吃着
2.回头再补下心里不好受的
3.如果和相邻有关，左看看，右看看
```
/*
某部队军训时，N个士兵排成一排进行打靶训练，教官给士兵分发子弹，教官会根据每个士兵的前期军训表现，预先给他们评分，评分输入用一个数组来表示，其评分值越大表示表现越好。

你需要按照以下要求，帮助教官给这些士兵分发子弹 :

1)每个士兵至少分配到 1 颗子弹。

2)相邻的士兵中，评分高的士兵必须获得更多的子弹。 那么，教官至少需要准备多少颗子弹呢 ?

示例 1 :

    输入 : [1, 0, 2]
    输出 : 5
    解释 : 教官最少可以分别给这三个士兵分发 2、1、2 颗子弹。
    示例 2 :

    输入 : [1, 2, 2]
    输出 : 4
    解释 : 教官最少可以分别给这三个士兵分发 1、2、1 颗子弹。第三个士兵只得到 1 颗子弹，这已满足上述两个条件。
    示例 3 :

    输入 : [1, 3, 2]
    输出 : 4
    解释 : 教官最少可以分别给这三个士兵分发 1、2、1 颗子弹。第三个士兵只得到 1 颗子弹，这已满足上述两个条件。
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;   
        }
        vector<int> candys;
        int start = ratings.at(0);
        candys.push_back(1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings.at(i) > start) {
                candys.push_back(candys.at(i - 1) + 1); 
            } else {
                candys.push_back(1);
            }
            start = ratings.at(i);
        }
        
        int end = ratings.at(ratings.size() - 1);
        
        for (int i = ratings.size() - 1 - 1; i >= 0; --i) {
            if (ratings.at(i) > end) {
                candys[i] = max(candys.at(i), candys.at(i + 1) + 1);
            }
            end = ratings.at(i);
        }
        
        int sum = 0;
        for (int i = 0; i < candys.size(); ++i) {
            sum += candys.at(i);
        }
        return sum;
    }
};
```
