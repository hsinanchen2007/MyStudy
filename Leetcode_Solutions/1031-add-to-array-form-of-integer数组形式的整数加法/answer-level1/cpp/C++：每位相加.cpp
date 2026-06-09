看到没人写c++的题解，想必各位大佬都不屑于做这么简单的题了，我一开始用了sum想把他们都累加起来，后来发现太天真了，总有一些数是没有办法保存的，所以看了官方的思路，写了c++，希望可以互相交流
```
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int last = K;
        for (vector<int>::size_type i = A.size(); i != 0; i--)
        {
            last = last + A[i-1];
            A[i-1] = (last) % 10;
            last = last/10;
            if(last==0) break;
        }
        while(last!=0)
        {
            A.insert(A.begin(), last%10);
            last /= 10;
        }
        return A;
    }
};
```
