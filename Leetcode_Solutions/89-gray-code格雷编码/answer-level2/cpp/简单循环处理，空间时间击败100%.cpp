序列长度和总位数的关系是2的n次方，n位的格雷码前半部分就是n-1位的格雷码l(n-1)，相当于最高位补0，后半部分就是l(n-1)的每个元素最高位补上1，由于相邻两个数只有1位有差异，所以后半部分翻转一下即可
则有l(n) = l(n-1) + reverse(l(n-1) | 1 << (n-1))
递归容易栈溢出，所以用循环实现比较好，下面是代码：
        ```
        vector<int> ret;
        // n==1和2的情况也可以加入到循环当中去
        if (n == 0) {
            ret.push_back(0);
        } else if (n == 1) {
            ret.push_back(0);
            ret.push_back(1);
        } else if (n == 2) {
            ret.push_back(0);
            ret.push_back(1);
            ret.push_back(3);
            ret.push_back(2);
        } else {
            ret.push_back(0);
            ret.push_back(1);
            ret.push_back(3);
            ret.push_back(2);

            int len, bits = 2;
            int prefix, i;
            while (bits < n) {
                prefix = 1 << bits;
                len = ret.size();
                // 倒序把前面的添加的数据高位补1，然后加到格雷码序列中
                for (i = len - 1; i >= 0; i--) {
                    ret.push_back(ret[i] | prefix);
                }
                bits++;
            }
        }

        return ret;
```
