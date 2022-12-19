网上有很多关于manacher算法的解释，但是都太过于复杂了，在做完这道题之后我发现manacher方法实际上是利用回文的对称性，即回文左边字符的回文半径为右边字符回文半径性的初始值（不一定相等，因为右边的回文半径还可以扩展,如abaaaabaaaaa，有且仅有全字符皆为回文字符，两个半径相等），若对称的左边字符回文半径超过该回文，则以右边符号到回文末尾为该字符的初始半径。
![image.png](https://pic.leetcode-cn.com/af18c8e08b43a2267fc70d31261b8a537706dc43ebaab2287584f4c1c201df7e-image.png)
设总长为N:
    第一种情况：因为互不相交，所以回文子串总的长度n<=N，则总体计算最差时间数为：O(3N/2) = O(N)
    第二种情况：设长串数为L,由于回文串长串不经过任何其他长串的中心，所以长串的前半段不相交，所以长串总长度n<=2N-L-a-1（a为最后一个子串的长度）,对于所有子串，只需要识别前半段，且回文对称传递的关系,相交处不需要计算，所以时间数最差情况为长串和子串都刚好互不相交，假设每个子串都有子串，则总的计算的时间数小于N+N/2+N/4+N/8...+L<2N即最坏时间复杂度O(2N) = O(N)
    第三种情况：由于通过对称传递回文属性后，还需对回文串进行扩充，所以根据回文对称传递，由于每次都是从前一个回文的尾部搜索的，所以最差的情况为中心刚好到前一个回文的尾部，假设回文长度为a1、a2、a3...aL，每个中心点都需要对外查找ai/2,则a1+a2/2+a3/2+a4/2...+aL/2 = N,则需要的时间数为N，子串也符合该情况，则同第二种情况，子串的搜索时间为也小于N,总的为O(2N) = O(N)。
    综合：结合三种情况中的推论最坏时间复杂度为O(n)

    int countSubstrings(string s) {
        int len = s.length();
        string manacher_s = "*#";
        for(int i=0;i<len;i++)
        {
            manacher_s+=s[i];
            manacher_s+="#";
        }
        manacher_s+="$";
        return manacher(manacher_s);
    }
    int manacher(string s)
    {
        int len = s.length();
        int index = 1;
        int sum = 0;
        vector<int> p(len,0);
        for(int i = 2;i<len-2;i++)
        {
            p[i] = max(0,min(index+p[index]-i,p[2*index-i]));
            while(s[i+p[i]+1] == s[i-p[i]-1]) p[i]++;
            if(i+p[i]>index+p[index]) index = i;
            sum+=(p[i]+1)/2;
        }
        return sum;
    }
结果为：
![image.png](https://pic.leetcode-cn.com/c18d6e34bfb13203024a8152913d4609b2cd6f4c9a848db0c2f2df72995f0d4e-image.png)
初来咋到，如有不正确的地方敬请指正。