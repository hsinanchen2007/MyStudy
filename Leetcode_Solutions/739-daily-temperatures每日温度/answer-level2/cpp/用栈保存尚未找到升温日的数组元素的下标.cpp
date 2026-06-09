### 解题思路
都在注释中

### 代码

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        //栈用来存储还 “没找到升温日的数组元素的下标”，因为存储了下标，也就能通过下标得到该数组元素的值
        stack<int> index; 
        vector<int> ret(T.size(), 0);
        
        for(int i = 0; i < T.size(); i++){
            
            //当栈不空时说明还存在数组元素没有找到升温日，如果此时的T[i]大于该元素则T[i]就是所找的升温日，因为栈中存的是尚未找到升温日的数组元素的下标，所以用i - stack.top()就能得到升温日到来还需要的天数；直到T[i]不大于栈中元素。
            while(!index.empty() && T[i] > T[index.top()]){
                ret[index.top()] = i - index.top();
                index.pop();
            }
            //栈中元素下标对应的数组元素肯定是递减的，否则一个后来的数入栈时，因为后来者大于栈中下标对应的数组元素，就会使栈中元素出栈了。

            //如果当前栈为空，或者当前T[i]不大于栈中下标对应的数组元素，则i也入栈，成为还 “没找到升温日的数组元素的下标” 集合中的一员。
            index.push(i);
        }

        //如果遍历完整个数组后栈中还存在  “没找到升温日的数组元素的下标”，则说明该下标处没有升温日，
        //所以ret[i] = 0，因此在一开始把ret初始化为全0，如果没被更改，仍然是0；

        return ret;
    }
};
```