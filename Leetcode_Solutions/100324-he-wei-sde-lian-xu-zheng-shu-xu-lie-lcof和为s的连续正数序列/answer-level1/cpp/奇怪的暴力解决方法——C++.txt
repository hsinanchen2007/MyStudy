**提交结果**
第一次提交：执行用时 :4 ms, 在所有 C++ 提交中击败了85.51%的用户；内存消耗 :9.2 MB, 在所有 C++ 提交中击败了100.00%的用户。
加注释后，第二次提交：8 ms, 在所有 C++ 提交中击败了54.51%的用户；内存消耗 :9.2 MB, 在所有 C++ 提交中击败了100.00%的用户。


**解题思路**
这个解体思路是通过找规律得来的。具体方法是，在target与各序列个数的商周围找序列元素。如下图所示：
![image.png](https://pic.leetcode-cn.com/cd7cc9f8187cbd0286e727eb52b2cbe4e495b3c93e1e1ed68e99ca30e8eaffab-image.png)
![image.png](https://pic.leetcode-cn.com/9adcfec6e3f7757fc26b3032a8b7bbece97c53846aa779d66227bc89d2b4a619-image.png)

1. 当序列中正整数的个数是偶数时
    target与序列中正整数的个数的商必须是 x.5 ，其他情况均不存在连续序列。比如target=10，序列个数为4，10/4=2.5，因此得序列[1,2,3,4]。
2. 当序列中正整数的个数为奇数时
    target必须整除序列中正整数的个数，其他情况均不存在连续序列。比如target=9，序列个数为3，9/3=3，得序列[2,3,4]。


**题解代码**
```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int target_temp = target / 2;//所有序列中的最大数
        int i,j;//用于循环
        int result_temp_quotient;//记录商
        int result_temp_remainder;//记录余数
        vector<vector<int>> S;//存放结果
        vector<int> res;//存放每一组序列
        for(i=target_temp;i>=2;i--){//某序列中共有i个数
            result_temp_quotient = target / i;
            result_temp_remainder = target % i;
            //若有偶数个正整数，其连续的序列必须为偶数个，因此，只有 target / i 为 x.5 时，才能存在相应序列
            if(i%2 == 0){//序列中有偶数个正整数
                if(result_temp_remainder == i/2){//target与i的商为x.5
                    res.clear();
                    j=target / i + 1 - i / 2;
                    if(j>0){//必须保证j>0，否则对于 target = 15，有可能出现 [0,1,2,3,4,5] 这种序列
                        for(j;j<=target / i + i / 2;j++){
                            res.emplace_back(j);
                        }
                        S.emplace_back(res);
                    }
                }
            }else{//i是奇数
                if(result_temp_remainder == 0){//target必须整除i
                    res.clear();
                    j=target / i - i / 2;
                    if(j>0){//同样必须保证j>0
                        for(j=target / i - i / 2;j<=target / i + i / 2;j++){
                            res.emplace_back(j);
                        }
                        S.emplace_back(res);
                    }
                }
            }
        }
        return S;//返回结果
    }
};
```
