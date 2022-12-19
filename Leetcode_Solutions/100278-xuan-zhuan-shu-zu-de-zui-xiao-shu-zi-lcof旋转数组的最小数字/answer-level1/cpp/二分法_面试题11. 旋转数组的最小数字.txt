### 解题思路
查找最小数，最开始想到的是最简单的直接遍历，能够在O(n)的时间复杂度内完成，也非常好实现。但这样简单就失去了出题的意义了吧！想到查找里面的算法，二分查找、堆查找、二叉树查找等都是O(logn)的时间复杂度，但是建堆和树都需要O(n)的复杂度，所以基于这样半有序数列使用二分查找无疑是最快的。二分查找这里有两个地方需要注意的：
1. 中间值的计算，为了防止数值过大溢出，一般可使用`mid = left + (rigth - left) / 2;`，也有使用移位进行除法计算的，可以看liweiwei大佬的博客，有详细讲解二分查找模板的博文[特别好用的二分查找法模板](https://www.liwei.party/2019/06/19/leetcode-solution-new/search-insert-position/)
2. 下一轮的选择，即mid的比较，可以找样例去尝试寻找比较的方法，因为最小值右边的序列肯定是有序的，那么以mid与right的值进行大小比较是解决的办法，当然比较左边道理相同。当mid比right值小，则下一轮在右边，大则在左边，等于的话是去掉可能的重复值，将right减1即可。

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
    if(numbers.empty()){
        return 0;
    }

    int left = 0, rigth = numbers.size() - 1, mid = 0;

    while (left < rigth) {
        mid = left + (rigth - left) / 2;
        if(numbers[mid] < numbers[rigth]){
            rigth = mid;
        } else if(numbers[mid] > numbers[rigth]) {
            left = mid+1;
        } else {
            rigth--;
        }
    }

    return numbers[left];
    }
};
```