### 解题思路


### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {

        int sum = 0;
        for(int i = 0; i < A.size(); ++i)
        {
            sum += A.at(i);
        }

        if(sum % 3 != 0) //不能分成三份和相等的
        {
            return false;
        }

        sum /= 3;  //每部分的和

        //每部分的整数个数不定 至少为1个 至多为size - 2个   前一部分的start index < 后一部分的start index
        //第一部分
        int part_sum = 0;
        int i = 0;
        for(; i < A.size() - 2; ++i) //从第一个到倒数第3个
        {
            part_sum += A.at(i);
            if(part_sum == sum)
                break;
        }
        
        if(i == A.size() - 2) //第一部分凑不出和
        {
            return false;
        }

        //第二部分
        ++i;
        part_sum = 0;
        for(; i < A.size() - 1; ++i) //从剩余的里面再凑到倒数第2个
        {
            part_sum += A.at(i);
            if(part_sum == sum)
                break;
        }

        if(i == A.size() - 1) //第二部分凑不出和
        {
            return false;
        }

        //第三部分
        ++i;
        part_sum = 0;
        for(; i < A.size(); ++i)
        {
            part_sum += A.at(i);
            if(part_sum == sum)
                break;
        }

        if(i == A.size()) //第三部分凑不出和
        {
            return false;
        }

        return true;
    }
};
```