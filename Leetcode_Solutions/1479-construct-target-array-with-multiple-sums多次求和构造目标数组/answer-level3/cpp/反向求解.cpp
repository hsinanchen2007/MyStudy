### 解题思路
题目要求返回false或者true，所以只需要判断能不能还原成全是1的数组就可以了。从[1,1,...,1]的形式的每一步变化的那一个元素都是变化后的元素最大值，所以反向来看，可以先找到元素的最大值，然后用这个最大值减去数组除这个最大值其他元素的和，当相减结果不为正，说明还原结束。最后判断还原之后的数组是否全为1，若是输出true，否则输出false。

过程中会出现int溢出的报错，这是因为计算数组非最大值元素和时出现溢出，只要加一个判断就好，一旦出现负数就break。

### 代码

```cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        vector<int> temp = target;
        int n = temp.size();
        while(1){
            int m = findMax(temp);
            int te = temp[m];
            for(int i = 0; i < n; ++i){
                if(i != m){
                    te = te - temp[i];
                    if(te < 0){
                        break;
                    }
                }
            }
            if(te > 0){
                temp[m] = te;
            }
            else{
                break;
            }
        }
        for(int i = 0; i < n; ++i){
            if(temp[i] != 1){
                return false;
            }
        }
        return true;
    }

    int findMax(vector<int>& vec){
        int temp = 0;
        int a = 0;
        int n = vec.size();
        for(int i = 0; i < n; ++i){
            if(vec[i] > temp){
                temp = vec[i];
                a = i;
            }
        }
        return a;
    }

};
```