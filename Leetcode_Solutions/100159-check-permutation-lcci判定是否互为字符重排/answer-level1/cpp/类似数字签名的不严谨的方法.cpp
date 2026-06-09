没有用到数组和排序。
字符串s1和s2的各个元素做异或。最终的结果相同，则可能是重排。（"aaaaa" & "bbbba"类为例外）。
两个字符串每个元素相加取模的结果相同，则可能是重排， sum1 % 128 == sum2 % 128。

两个条件做约束。耗时0ms， 内存8.3M.

```c++ []
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;

        unsigned char xor_s1 = 0, xor_s2 = 0;
        int mod_s1 = 0, mod_s2 = 0;

        for(int i = 0; i < s1.length(); ++i){
            xor_s1 = xor_s1 ^ s1[i];
            xor_s2 = xor_s2 ^ s2[i];

            mod_s1 = (mod_s1 + s1[i]) % 128;
            mod_s2 = (mod_s2 + s2[i]) % 128;
        }

        return xor_s1 ^ xor_s2 == 0 && mod_s1 == mod_s2;
    }
};
```

