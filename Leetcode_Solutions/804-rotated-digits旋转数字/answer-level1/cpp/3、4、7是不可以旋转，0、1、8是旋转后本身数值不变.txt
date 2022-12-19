### 解题思路
遍历查找符合要求的数字就可以了。

### 代码

```cpp
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        int flag1 = 0;
        int flag2 = 0;
        for (int i = 2; i <= N; ++i)
        {
            //flag1、flag2每次都要置0
            flag1 = 0;
            flag2 = 0;
            int num = i;
            while (num > 0)
            {
                int tmp = num % 10;
                //含有3、4、7其中一个就无法旋转，必不是好数
                if (tmp == 3 || tmp == 4 || tmp == 7)
                {
                    flag1 = 1;
                    break;
                }
                //含有2、5、6、9其中一个旋转后才会改变数值
                else if (tmp == 2 || tmp == 5 || tmp == 6 || tmp == 9)
                {
                    flag2 = 1;
                }
                num /= 10;
            }
            if (flag1 == 0 && flag2 == 1)
            {
                //cout << i << " ";
                ++count;
            }
        }
        return count;
    }
};
```