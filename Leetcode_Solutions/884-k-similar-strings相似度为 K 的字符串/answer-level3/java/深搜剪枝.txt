深搜大概是最直观的解法了，搜索第一个不相等的字符，从原字符串中找到与之相等的字符换位，然后再往下替换，直到字串相等，每一层搜索相当于相似度K+1，最后挑选出最优的K作为结果。
深搜抽象理解为：KSimilarity(A, B) = KSimilarity(C + A`, C + B`) + 1，其中A在做一次互换操作后得到两个字串C和A`。
当然试过直接用深搜的应该会boom，因为深搜太慢了，所以我们需要通过剪枝优化。
首先对于开始的字串，如果存在A[i] == B[i]，则该位置一定不会互换，可以去除。
其次在深搜过程中，如果出现A[i]和A[j]互换后，A[i]=B[j]，则一定为最优互换。
因此利用indexOf可以快速得到所有的互换情况，然后有最优互换的情况下挑选最优互换，否则对每次互换进行比较。

深搜50ms，不算很快，但是对于直观解法来说算是比较优了。时间复杂度跟交换次数和可剪枝次数有关，对于
```
"aaaaabbbbbcccccddddd"
"dddddaaaaabbbbbccccc"
```
这类的样例几乎都会超时。
当然用第二个题解的两个样例都是超时的。

```
class Solution {
    public int kSimilarity(String A, String B) {
        //对开始字串进行剪枝
        StringBuilder a = new StringBuilder();
        StringBuilder b = new StringBuilder();
        for(int i = 0; i < A.length(); i++){
            if(A.charAt(i) != B.charAt(i)){
                a.append(A.charAt(i));
                b.append(B.charAt(i));
            }
        }
        return subKSimilar(a.toString(), b.toString());
    }
    
    public int subKSimilar(String A, String B){
        if(A.equals(B)){
            return 0;
        }
        int index = 0;
        //找出第一个不同字串
        while(index < A.length()){
            if(A.charAt(index) != B.charAt(index)){
                break;
            }
            index += 1;
        }
        char tar = B.charAt(index);
        int t = 0;
        int k = 9999;
        Boolean flag = true;//寻找最优模式
        while(t != -1){
            t = A.indexOf(tar, t + 1);
            if(t == -1){
                if(flag == false)
                    return k;
                else{
                    //当没有最优互换情况下，重新进行普通互换
                    flag = false;
                    t = 0;
                    continue;
                }
            }
            if(flag){
                if(A.charAt(index) != B.charAt(t)){
                    continue;
                }
            }
            StringBuilder sb = new StringBuilder(A);
            sb.replace(t, t + 1, String.valueOf(A.charAt(index)));
            int tempK = 1 + subKSimilar(sb.toString().substring(index + 1), B.substring(index + 1));
            if(A.charAt(index) == B.charAt(t)){
                return tempK;
            }
            if(tempK < k){
                k = tempK;
            }
        }
        return k;
    
    }
}
```
