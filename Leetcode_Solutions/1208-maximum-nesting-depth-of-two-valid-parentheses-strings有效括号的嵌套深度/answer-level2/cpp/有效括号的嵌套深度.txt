### 解题思路
方法一：异或
1^1 = 0
1^0 = 1
让相连的左（右）括号分在不同的集合当中

方法二：对半分
设置一个flag，大于flag的为A部分，小于则为B部分
flag = 最大值>>1

方法三：奇偶性
深度奇数为0  
深度偶数为1
ans[idx++]=  c=='('  ? idx&1 : ((idx + 1)&1);

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int len = seq.length();
        vector<int> res(len,0);
        int tmp=1;
        for(int i=0;i<len;i++){
            if(seq[i] == '('){
                tmp ^= 1;
                res[i]=tmp;
            }
            else{
                res[i]=tmp;
                tmp ^= 1;
            }
        }
        return res;
    }
};
```