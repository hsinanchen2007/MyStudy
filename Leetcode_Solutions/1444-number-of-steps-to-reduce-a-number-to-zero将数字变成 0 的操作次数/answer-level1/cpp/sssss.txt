### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {

        if(num==0)
        return 0;
        int a=1;
        int result=0;
        while(num!=0)
        {
            if(num&a&&num!=1)
            result+=2;
            else
            result+=1;

            num=num>>1;
            cout<<num<<endl;
        }

        return result;

    }
};
```