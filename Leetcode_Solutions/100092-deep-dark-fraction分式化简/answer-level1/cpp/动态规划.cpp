### 解题思路
这是第一次靠自己的思考，将题目写出来，但是并不是很完美，没有考虑，分子分母约分的问题，后面会考虑进去的，思路其实就是将手算的步骤还原出来，因为这道题的特点是，连分数都是分子为1的形式，所以直接交换分子分母，就相当于执行了一次被除的操作，另外，不是很清楚的是，vector的用法，希望能够有人指点。

### 代码

```cpp
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        //vector<int> ret[2];
        int molecule = 1;   //分子
        int denominator;//分母
        int t;
        //ret.size();
        denominator = cont[cont.size() - 1];                  //初始化为An
        for(int i = cont.size() - 1; i > 0; i--){   //2 - 1 = 1, !> 1
            molecule = denominator*cont[i - 1] + molecule;  //分母*cont[i - 1] + 现分子
            //denominator = cont[i];                          //
            t = molecule;       //swap
            molecule = denominator;
            denominator = t;
            //swap(molecule,denominator);
        }
        swap(molecule,denominator);     //循环出来的时候不要交换，所以得换回去
        return {molecule,denominator};
    }
};
```