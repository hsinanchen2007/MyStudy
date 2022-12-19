1.  规律：kthGrammar(k)=computeParity(k-1) 即第k个字符等于整数k-1的偶校验位.
如kthGramar(5)=computeParity(4)=computeParity(00000100)=1
    ```
    int kthGrammar(int N, int K) {
        return computeParity(--K);
    }
    ```
 
 2. 奇偶校验位计算：
    ```
    int computeParity(int i)//针对int类型的基于乘法的偶检验位求解,详解[http://graphics.stanford.edu/~seander/bithacks.html](bit twiddling hacks)
    {
        i^=i>>1;
        i^=i>>2;
        i=(i&0x11111111U)*0x11111111U;
        return (i>>28)&1;
    }
    ```



