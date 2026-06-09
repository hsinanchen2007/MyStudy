#描述
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
#题解
1.multiset的使用，时间：nlogk,空间logk 小到大排序
2.直接快排，sort(arr.begin(), arr.end()); 时间：nlogn,空间logn
3.

BTW:大到小排序方法： sort(arr.begin(), arr.end()，greater<int>() )
```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        multiset<int> mset;
        for(auto a:arr){
            mset.insert(a);
            if(mset.size()>k){
                mset.erase(--mset.end());
            }
        }
        vector<int> res;
        for(auto b:mset){
            res.push_back(b);
        }
        return res;
    }
};
```