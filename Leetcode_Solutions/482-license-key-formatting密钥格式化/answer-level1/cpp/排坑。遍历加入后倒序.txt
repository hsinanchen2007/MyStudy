### 解题思路
注意题目可能会被忽略的地方：
    除了第一个分组之外，其他的分组都必须要是k位的。
    
所以先倒序遍历：
    先把其他的分组的k位组好之后，剩下的位数（小于k位）即是第一组的位数。

### 代码

```cpp
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string re = "", temp = "";
        int j = 0;
        
        for(int i = S.length()-1; i>=0; i--){
            if(S[i]!='-' && j++<K){
                if(S[i]>=97 && S[i]<=122) S[i] -= 32;
                temp += S[i];
            }
            // 如果已经到了K个字母 或者 已经到了S的第一个字符但是未满K 
            if(j==K || (i==0&&j<K)) {		 
                re += temp;
                re += '-';
                temp = "";
                j = 0;
            }
        } 

        for(int i = re.length()-1; i>=0; i--){      // 看看末尾有没有多出来的'-'
            if(re[i]!='-') break;
            else j++;       // 上面 j 最后已经等于0了，这里直接拿来用即可。
        }
	
        re = re.substr(0, re.length()-j);	// 把最后多出来的'-'删掉 
        reverse(re.begin(), re.end());		// 翻转字符串 
        return re;
    }
};
```