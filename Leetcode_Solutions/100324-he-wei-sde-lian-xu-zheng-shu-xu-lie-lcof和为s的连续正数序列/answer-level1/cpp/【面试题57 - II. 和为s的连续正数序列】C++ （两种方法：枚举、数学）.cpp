### 方法一：枚举+暴力循环

首先，至少含有两个数字说明，第一个数字属于1到floor(s/2)
然后依次按照第一个数字从1开始枚举，暴力循环累加知道大于等于target，再判断是否==target

时间复杂度：$O(\text { target } \sqrt{\text { target }})$
空间复杂度：$O(1)$

### 代码

```cpp
class Solution {
    //至少含有两个数字说明，第一个数字属于1到floor(s/2)

public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> tmp_res;
        if(target<=2)   //特殊情况0，1，2，直接返回
            return res;

        int n = int(target/2);
        int i, j, sum;
        // 枚举第一个数字i
        for(i = 1; i<=n; i++){
            sum = 0;
            j = i;
            //循环累加
            while(sum<target){
                sum += j;
                j++;
            }
            //判断结果是否等于target
            if(sum>target)
                continue;   //不等于，继续枚举
            else{    //等于，构造序列tmp_res，插入到res
                for(int k = i; k<=j-1; k++)
                    tmp_res.emplace_back(k);
                res.emplace_back(tmp_res);
                tmp_res.clear();   //清空
            }
        }
        return res;
    }
};
```


### 方法二：数学分析

首先，假设序列的起点为$x$、终点为$y$，则由等差数列求和：
$x+(x+1)+\cdots+y=\frac{(x+y) *(y-x+1)}{2}=\text { target }$
以$y$为变量，解$y^{2}+y-x^{2}+x-2 *$ target $=0$即可（注意舍掉小于0的根）

时间复杂度：$O(1)$
空间复杂度：$O(1)$

**注意：计算delta的时候要用到`*1ll`**
`ll`代表`long long`, `*1ll`是为了在计算时，把`int`类型的变量转化为`long long`，然后再赋值给`long long`类型的变量。否则会报错int溢出。。。
![image.png](https://pic.leetcode-cn.com/a8f31afd3a3237d0da8990c58af1924e1371cd996c1722ea847b2d833d139d70-image.png)

### 代码
```cpp
class Solution {
    //数学方法
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> tmp_res;
        if(target<3)
            return res;

        int n = int(target/2);
        for(int x = 1; x<=n; x++){
            // cout<<"x:"<<x<<endl;
            long long delta = 1 - 4*(-1ll*x*x+x-2*target);
            // cout<<"delta:"<<delta<<endl;
            if(delta<0)  //无解
                continue;
            int delta_sqrt = (int)sqrt(delta);
            //条件：delta开根号为整数且-b+delta是偶数（因为要除2a=2）
            if (1ll*delta_sqrt * delta_sqrt == delta && (delta_sqrt - 1) % 2 == 0){
                int y = (-1 + delta_sqrt) / 2;
                if (x < y) {
                    for (int i = x; i <= y; ++i) 
                        tmp_res.emplace_back(i);
                    res.emplace_back(tmp_res);
                    tmp_res.clear();
                }
            }
        }
        return res;
    }
};
```


