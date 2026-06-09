```
class Solution {

public:

    vector<vector<int>> findContinuousSequence(int target) {

        stack<int> lens;

        stack<int> a;

        vector<vector<int>> res;

        int n=0;

        int a1=0;

        for(int i=2;(target-i*(i-1)/2)/i>0;i++){

            if((target-i*(i-1)/2)%i==0){

                lens.push(i);

                a.push((target-i*(i-1)/2)/i);

            }

        }

        while(!lens.empty()&&!n_a1.empty()){

            n=lens.top();
            lens.pop();
            a1=a.top();
            n_a1.pop();

            vector<int> vec;

            for(int i=0;i<n;i++){

                vec.push_back(a1);

                a1++;
            }

            res.push_back(vec);

        }

        return res;

    }
};
```

解决这个问题不难，就是简单的高中递增数列的求和  

求和公式：Sn = n * a1 + n*(n-1)*d/2

或者是：Sn = n*(a1+an)/2

    Sn是递增数列之和，n为数列中的元素的个数，a1是数列的首项，an是数列的第n项，d为公差

这里选择第一个公式，因为Sn已知，将n或a1递增可以得到另一个变量的值

将公式变形得：

a1 = (Sn-n*(n-1)*d/2)/n

其中d已知为1（即公差为1）

所以

a1 = (Sn-n*(n-1)/2)/n

在这里递增变量n就可以得到所有符合公式的 a1 和 n ：

```
for(int i = 2 ; (target - i*(i - 1)/2)/i > 0 ; i++){

            if((target - i*(i - 1)/2)%i == 0){

                //a和lens为栈，分别用来存储 a1 和 n

                lens.push(i);

                a.push((target - i*(i - 1)/2)/i);

            }

        }

```
    首先，这里选用n作为递增量的原因是在公式中，n的次数大于1，不好分离变量，选用栈的原因是题目要求“序列
    内的数字由小到大排列，不同序列按照首个数字从小到大排列”，栈的FILO（First In Last Out）的特性可以满
    足题目要求。


这里循环应该满足的要求为`target - i*(i - 1)/2)/i > 0 && （target - i*(i - 1)/2)%i == 0` 要满足后面 

(target - i*(i - 1)/2)%i == 0 这个条件的原因是a1是整数，所以(Sn-n*(n-1)/2)要能被n整除才能满足要求。

算法的时间复杂度为*O(n)*，空间复杂度为*O(1)*

![image.png](https://pic.leetcode-cn.com/71b36ecff895e5d4a092b20773fb5f19a75dd31a1e9959df5a664f9660c9478c-image.png)
