题目要求 arr1 中元素的相对顺序和 arr2 中的相对顺序相同，那我们对 arr2 进行次遍历，按其顺序依此将 arr2 的元素添加到结果容器中。但问题就是不知道 arr2 中的每个元素在 arr1 中出现了多少次，也就是说对于arr2中的每一个元素，我们不知道应该往结果容器中添加多少次。
解决之道就是对 arr1 也进行一次遍历，因为0 <= arr1[i], arr2[i] <= 1000，所以我们可以初始化一个大小为1001的计数容器来对 arr1 中的元素进行计数，计数容器的下标代表元素的值，计数容器中某一位置的内容代表值等于该位置下标的元素出现在arr1中的次数。
如此一来，问题就解决了。对于 arr1 中不存在于 arr2 的元素，我们在最后对计数容器进行一次从0到1000的遍历即可，对值大于0的元素将其下标添加到结果容器中。

```
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001,0);  //用于计数,下标代表元素值，内容代表相应值（等于下标）在arr1中出现的次数
        vector<int> result; //用于输出结果
        for(auto i:arr1)
            ++count[i];
        for(auto i:arr2)
        {
            while(count[i])
            {
                result.push_back(i);
                --count[i];
            }
        }
        for(int i=0;i<=1000;++i)
        {
            while(count[i])
            {
                result.push_back(i);
                --count[i];
            }
        }
        return result;
    }
};
```
