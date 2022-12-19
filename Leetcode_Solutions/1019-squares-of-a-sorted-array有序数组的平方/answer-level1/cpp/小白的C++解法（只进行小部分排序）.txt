首先利用题干给出的有序条件，得知数组中有一个位置是正负数的分界点。
我们根据find_if()方法找出这个正负数分界点，然后我们再通过find_if()方法找出第一个大于 负对头元素 的分界点（比如队头是-2，那么我们找出第一个大于2的点）。
这样我们有了两个位置，根据正负数分界点（代码中的zero），将所有的负数乘-1得到正数，然后根据第二个分界点（代码中Greater_head_element）将它之前的部分进行排序。
最后进行平方。

如果队头元素大于等于0，那么直接进行平方操作即可。

```
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = A.size() - 1;
        //如果队头元素大于0，则直接进行平方
        if(A.front() >= 0)
        {
            while(i>=0)
            {
                A[i] = pow(A[i], 2);
                i--;
            }
            return A;
        }

        //找到第一个大于0的位置,返回值为迭代器类型
        auto zero = find_if(A.begin(), A.end(), bind2nd(greater<int>(), 0)); 

        //找到第一个大于负队头元素的位置，返回值为迭代器类型
        auto greater_head_element = find_if(A.begin(), A.end(), bind2nd(greater<int>(), -A.front())); 

        vector<int>::iterator it = A.begin();
        //将负数转为正数
        for(it = A.begin(); it != zero; it++)
        {
            *it *= (-1);
        }

        //排序
        sort(A.begin(), greater_head_element);

        //平方
        while(i>=0)
        {
            A[i] = pow(A[i], 2);
            i--;
        }
        return A;
    }
};
```


![TIM图片20191111221858.png](https://pic.leetcode-cn.com/2d2f9d6f8218f1d194e6c770225806826b4f1bdd7db5766fd995f209e4089202-TIM%E5%9B%BE%E7%89%8720191111221858.png)

