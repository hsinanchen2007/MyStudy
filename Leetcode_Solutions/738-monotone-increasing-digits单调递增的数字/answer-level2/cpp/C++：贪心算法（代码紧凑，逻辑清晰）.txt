**题解：**
贪心算法，遍历数字每一位，当前位的数字比下一位的数字大，则将该位数字减小1，然后之后位的数字全部变为9

**代码如下：**
```cpp
class Solution {
public:
    //题解：贪心算法，遍历每一位数字，当前位的数字比下一位的数字大，则将该位数字减小1，然后之后位的数字全部变为9
    int monotoneIncreasingDigits(int N) {
        if(N<10)return N;
        deque<int> num;//将N转换为一连串数字，避免转换为字符串
        while(N)
        {
            num.push_front(N%10);
            N/=10;
        }
        int size=num.size();
        for(int i=0;i<size-1;++i)
        {
            if(num[i]>num[i+1])
            {
                num[i]--;
                for(int j=i+1;j<size;++j)num[j]=9;
                i=-1;//在if语句结束后，i++会变为0的
            }
        }
        int result=0;
        for(int n:num)result=result*10+n;//还原为数字
        return result;
    }
};
```
