### 解题思路
首先利用hash数组记录数组arr1中各个数字出现的次数，再按照arr2中的顺序进行遍历输出，存入结果数组res，每输出一次对应hash数组中数字个数减少1，直到为0进入下一个数字。

因为题目中提示数字最大不超过1000，故最后可以遍历hash数组看哪些数字不为0，继续进行升序输出即可。

![微信图片_20200203174950.png](https://pic.leetcode-cn.com/c692d84a9d3fbc1c7978aaf138ed431f87051e148773caed7ec717d8ee0afb29-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200203174950.png)

### 代码

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int hash[1010] = {0};
        vector<int> res;
        for(int i = 0; i < arr1.size(); i++){
            hash[arr1[i]]++;                    //hash数组记录arr1数组中数字出现次数
        }
        for(int i = 0; i < arr2.size(); i++){   //遍历arr2数组
            while(hash[arr2[i]]){               //当前数字还没被输完
                res.push_back(arr2[i]);         //按arr2的顺序存入结果数组
                hash[arr2[i]]--;
            }
        }
        for(int i = 0; i <= 1000; i++){         //输出剩余数字即可
            while(hash[i]){
                res.push_back(i);
                hash[i]--;
            }
        }
        return res;
    }
};
```