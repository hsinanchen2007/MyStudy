![深度截图_选择区域_20200330045018.png](https://pic.leetcode-cn.com/440948bee07b4b07b61f508876ebefedbfe7ac82fd3525a8d44a682e4ab9b2b3-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20200330045018.png)

### 解题思路：

分析可能的三种情况，简单的写出代码。



### 9，9，9，9

  可以想到，加1之后进位，并产生新的数字的情况**只有每一位都是9**。

  所以这个可以作为一种特殊情况单独写。

### 1，2，3，4 & 1，9，9，9


  解决第一种特殊情况之后，我们可以保证其他情况都不会产生新的位（原来是几位就是几位）。

  设立一个虚拟的指针p从后往前遍历。

  **digit[p] + 1 只会小于等与1**

  **如果digit[p]+1 == 10** , 那么让digits[p] = 0,并让p -- ，并让前一位做相同的操作。

  **如果digit[p]+1 != 10** , 那么让digits[p] = digits[p]+1，此时可以结束循环



```c++
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();

        // 9..9
        //遍历一遍digits
        //如果存在不等于9的位，flag = 0
        //否则flag再循环结束的时候会保持1不变
        int flag = 1; 
        for(int i = 0 ; i < len ; i++)
            if(digits[i] != 9){
                flag = 0;
                break;
            }
        if(flag){	//确认是9..9的格式
            digits[0] = 1;
            for(int i = 1; i < len ;i++)
                digits[i] = 0;
            digits.push_back(0);
            return digits;
        }
		
        //1234 && 1999
        //设立p指针从最后以为向 ← 遍历
        //temp用来保存digits[p]+1
        //再次用到flag变量，如果在计算过程中没有进位（temp!=10）,则可以提前结束循环
        int p = len - 1;
        int temp;
        flag = 1;
        while(flag && p >= 0){
            temp = digits[p] + 1;
            digits[p] = temp%10;
            if(temp != 10) flag = 0;
            p--;
        }

        return digits;
    }
};
```