第一种计数排序，先统计每个arr1中每个数字i出现的次数n\_i，然后遍历arr2中的每个索引j，根据统计结果将j输出n\_j次。最后把剩下的元素按从小到大顺序输出出来（就是把统计数组中的每一个元素输出）。

```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;
        int counter[1001] = {0}; 
        for (auto it = arr1.begin(); it != arr1.end(); ++it){
            counter[*it] ++;
        }
        for (auto it = arr2.begin(); it != arr2.end(); ++it){
            for (auto i=0; i < counter[*it]; ++i){
                result.push_back(*it);
            }
            counter[*it] = 0;
        }
        for (auto i = 0; i < 1001; ++i){
            if (counter[i] != 0){
                for (auto j=0; j < counter[i]; ++j){
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};
```

第二种方法是按特殊argument排序。正常的排序是按数字字面大小排序，但这道题可以先为每一个数字构建一个argument来表示“特殊的”大小。然后sort的时候按照这个新的argument排序。

需要维护一个argument数组，保存1001个数字每一个对应的argument。（其实就是一个map/dictionary）。

例如arr2 = {2,1,4,3,9,6}时，这个argument数组可以是（只显示前10个元素）: {9999, -1000, -1001, -998, -999, 9999, -996, 9999, 9999, -997, ...}。然后根据这个argument作为排序依据。

C++实现使用了lambda表达式和内置sort。

```
int arguments[1001];
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // prepare argument
        fill_n(arguments, 1001, 9999);
        int counter = -1001;
        for (auto it = arr2.begin(); it != arr2.end(); ++it){
            arguments[*it] = counter;
            counter ++;
        }

        // sort
        sort(arr1.begin(), arr1.end(), [](const int & a, const int & b) -> bool{
            int arg_a = arguments[a] != 9999 ? arguments[a] : a;
            int arg_b = arguments[b] != 9999 ? arguments[b] : b;
            return arg_a < arg_b;
        });

        return arr1;
    }
};
```

感觉第二个方法更优雅一些，结果耗时比第一个慢：方法1是4ms，方法2是8ms。