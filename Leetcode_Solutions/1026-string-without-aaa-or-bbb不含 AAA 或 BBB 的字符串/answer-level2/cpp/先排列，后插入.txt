如果A < B，我们先排列A个'ba'，然后把剩下的B-A个'b'插入到指定位置中；
如果B < A，先排列B个'ab', 然后把剩下的'a'插入。

```
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string result = "";

        if(A >= B)
        {
            for (int i = 0; i < B; i++)
            {
                result += "ab";
            }

            for(int i = 0; i < A -B; i++)
            {
                if(i*3+1 <= result.length())
                    result.insert(i*3+1, 1, 'a');
                else result += 'a';
            }
        }
        else{
            for(int i = 0; i < A; i++)
            {
                result += "ba";
            }
            for(int i = 0; i < B - A; i++)
            {
                if(i*3+1 <= result.length())
                result.insert(i*3+1, 1, 'b');
                else result += 'b';
            }
        }

        return result;
    }
};
```
