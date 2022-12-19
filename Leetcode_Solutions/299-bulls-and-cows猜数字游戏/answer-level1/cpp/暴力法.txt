### 解题思路
1.按位对比求出公牛数量
2.排序完按位对比求出公牛和奶牛总数量

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int count = secret.size();
        int countA = 0;
        int countB = 0;
        vector<int> arrA;
        vector<int> arrB;
        for (int i=0; i<count; i++)
            arrA.push_back(secret[i]-48);
        for (int i=0; i<count; i++)
            arrB.push_back(guess[i]-48);

        //获取公牛的数量
        for (int i=0; i<count; i++)
        {
            if (arrA[i] == arrB[i])
                countA++;
        }
        
        int temp;
        //给两个数组排序
        for (int i=0; i<count-1; i++)
        {
            for (int j=i+1; j<count; j++)
            {
                if (arrA[i] > arrA[j])
                {
                    temp = arrA[i];
                    arrA[i] = arrA[j];
                    arrA[j] = temp;
                }
                if (arrB[i] > arrB[j])
                {
                    temp = arrB[i];
                    arrB[i] = arrB[j];
                    arrB[j] = temp;
                }
            }
        }

        //获取奶牛的数量
        int a=0;
        int b=0;
        while (a < count && b < count)
        {
            if (arrA[a] < arrB[b])
                a++;
            else if (arrA[a] > arrB[b])
                b++;
            else
            {
                a++;
                b++;
                countB++;
            }
        }

        string str;
        str = to_string(countA) + "A" + to_string(countB-countA) + "B";
        return str;
    }
};
```