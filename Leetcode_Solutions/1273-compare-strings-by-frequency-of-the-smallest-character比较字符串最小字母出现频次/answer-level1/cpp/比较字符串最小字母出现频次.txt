基础思路：遍历queries数组，对于每个元素遍历words数组，对于每个queries数组中的元素和words数组中的元素调用f函数计算结果，然后如果f(queries[i]) < f(W)就累加。
改进1：words数组中的元素调用f函数的结果是不变的，所以可以先计算好存入fwords数组中，就不用每次遍历到再计算了
改进2：既然已经得到了fwords数组，求N次fwords数组中有多少个数大于某数x，可以排序后二分查找（时间复杂度O(NlogN)），比直接遍历查找（时间复杂度O(N^2)）要快。

执行用时 : 20 ms , 在所有 cpp 提交中击败了 99.06% 的用户
内存消耗 : 11 MB , 在所有 cpp 提交中击败了 100.00% 的用户
```
class Solution {
public:
    int f(string& s) {
        char min = s[0];
        int count = 1;
        int length = s.length();
        for (int i = 1; i < length; i++) {
            if (s[i] < min) {
                min = s[i];
                count = 1;
                continue;
            }
            if (s[i] == min) {
                count++;
            }
        }
        return count;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> result;
        vector<int> fwords;
        //先计算好words数组中每个元素调用f函数的值，存到fwords数组中
        for (auto it = words.begin(); it != words.end(); it++) {
            fwords.push_back(f(*it));
        }
        sort(fwords.begin(), fwords.end());
        int size = fwords.size();
        for (auto it = queries.begin(); it != queries.end(); it++) {
            int fquery = f(*it);
            //对于每个f(queries[i])，用二分查找找到应该插入的位置，再用size减去位置，就得到了数组中比它大的元素个数
            result.push_back(size - (upper_bound(fwords.begin(), fwords.end(), fquery) - fwords.begin()));
        }
        return result;
    }
};
```
时间复杂度：第一次遍历words数组O(N\*M)（N为数组长度，M为字符串长度），排序时间复杂度O(NlogN)，遍历queries数组O(N\*M\*logN)（二分查找时间复杂度O(logN)），总时间复杂度O(N\*M\*logN)
空间复杂度：O(N)