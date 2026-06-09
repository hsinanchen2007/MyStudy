# 思路：
1. 从后向前遍历数组，使用tag记录当前位加1后的结果，再将tag%10赋给当前位。当出现以下情况之一时停止遍历：

1⃣数组已遍历完成（此时如果首位是9，加1后需*进位*（即在数组最前面插入一个1），因此需要进行2.中的判断）

2⃣当前位加1后不需要进位，即tag<10。

2. 如果*原数组首位*（如果i<0则tag为原数组首位加1结果）加1结果大于10，需要进位，使用insert()函数在数组前面插入一个1。

# 代码：

```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int tag = 0;    //tag记录当前位加1后的结果
        while(i >= 0)   //判断数组是否遍历完成
        {
            tag = digits[i] + 1;
            digits[i--] = tag % 10;
            if(tag < 10)break;  //如果当前位加1后不需要进位，则停止遍历
        }
        //如果原数组首位加1结果大于10，需要进位
        if(i < 0 && tag >= 10)digits.insert(digits.begin(),1);  
        return digits;
    }
};
```
