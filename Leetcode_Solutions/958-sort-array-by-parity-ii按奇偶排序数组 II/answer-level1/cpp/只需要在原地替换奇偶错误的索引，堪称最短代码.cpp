

![微信图片_20190929112107.png](https://pic.leetcode-cn.com/3a2adaf5741e455452b78f1113693f2ab6ddad781e59f4dcb28e4d9d67b37393-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20190929112107.png)

直接上代码
```c++
vector<int> sortArrayByParityII(vector<int> &A) {
        int j = 1;//记录奇数索引
        for (int i = 0; i < A.size(); i += 2) {
            if ((A[i] & 1) == 0) continue;//奇偶对的上就不用看了
            else {
                while ((A[j] & 1) != 0) { j += 2; }//奇数索引，奇偶对的上的以后就跳过了;
                swap(A[i], A[j]);j+=2;//对不上就地替换，注意，替换之后显然奇偶就对了，所以奇数索引也增加2
            }
        }
        return A;
    }
```