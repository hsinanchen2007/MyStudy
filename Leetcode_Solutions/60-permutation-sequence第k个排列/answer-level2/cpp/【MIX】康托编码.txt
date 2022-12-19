### 解题思路
使用康托编码求解

### 代码

```java []
class Solution {
    public String getPermutation(int n, int k) {
        // 记录阶乘值
        int []factorials = new int [n];
        Arrays.fill(factorials, 1);
        // 记录字符排列状态
        List<Integer> nums = new ArrayList<>(){{add(1);}};
        for(int i=1; i<n; ++i){
            factorials[i]=factorials[i-1]*i;
            nums.add(i+1);
        }

        // step 1
        --k;

        // step 2
        StringBuilder sb = new StringBuilder();
        for(int i=n-1; i>=0; --i){
            int index = k/factorials[i];
            k -= index*factorials[i];

            sb.append(nums.get(index));
            nums.remove(index);
        }

        return sb.toString();
    }
}
```
```python []
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        # 得到阶乘数组和排列数组
        factorials = [1 for _ in range(n)]
        nums = ['1']
        for i in range(1, n):
            factorials[i] = i*factorials[i-1]
            nums.append(str(i+1))

        # step 1
        k-=1

        # step 2
        res = []
        for i in range(n-1, -1, -1):
            index = k//factorials[i]
            k -= index*factorials[i]
            res.append(nums[index])
            nums.remove(nums[index])

        return ''.join(res)
```
```c++ []
class Solution {
public:
    string getPermutation(int n, int k) {
        // 康托编码求解
        string s(n, '0');
        string result;
        for(int i=0; i<n; ++i)
            s[i] += i+1;
        if(n == 1)
            return s;
        return kth_permutation(s, k);
    }

private:
    int factorial(int n){
        if(n == 1)
            return 1;
        return n*factorial(n-1);
    }

    template<typename Sequence>
    Sequence kth_permutation(const Sequence& seq, int k){
        const int n = seq.size();
        Sequence S(seq);
        Sequence result;

        int base = factorial(n-1);
        --k;
        for(int i=n-1; i>0; k%=base, base/=i, --i){
            auto a = next(S.begin(), k/base);
            result.push_back(*a);
            S.erase(a);
        }

        result.push_back(S[0]);
        return result;
    }
};
```