### 解题思路
1. 用长度为$26$的数组，先统计`B`中各个字符的最多长度。比如 `B=["aa", "aaab"]`，则统计结果为 `C[a]=3, C[b]=1, C[c]=0, ...`。
2. 依次看`A`中的字符串，例如`a`，是否包含`C`中的所有个数的字符，如果满足条件，则把其加入结果中。具体实现为从`C`中依次减去`a`中字符，如果最终还有出现次数大于$0$的字符，说明不满足条件，比如`a="abc"`，`B,C`如步骤 1 中所示，减完后 `C[a]=2, C[b]=0, C[c]=-1,...`，`C[a]>0`，说明`abc`不满足要求；
3. 实现中，因为`C`中的信息每次比较时均需要，因此使用了`C2`临时数组来辅助完成，

### 代码

```cpp
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		char C[26];
		char C2[26];
		memset(C, 0, sizeof(C));
		vector<string> ans;

		for(auto& b:B) { // 依次统计 B 中字符串字符出现次数
			memset(C2, 0, sizeof(C2)); 
			for(int i=0; i<b.size(); i++) {
				C2[b[i]-'a'] += 1;
			}
			
			for(int i=0; i<26; i++) // 如果某个字符出现次数更多，更新次数
				if(C2[i] > C[i])
					C[i] = C2[i];
		}
		
		for(auto& a:A) { // 对 A 中每个字符串遍历，看是否满足条件
			for(int i=0; i<26; i++) // C2 = C
				C2[i] = C[i];
			
			for(int i=0; i<a.size(); i++) { // 出现的字符让次数减 1
				int j = a[i] - 'a';
				C2[j] -= 1;
			}
			
			bool ok = true;
			for(int i=0; i<26;i++) { // 看减去出现字符后是否所有字符出现次数 ≤ 0
				if(C2[i] > 0) {
					ok = false;
					break;
				}
			}
			
			if(ok) // 满足的字符串
				ans.push_back(a);
		}
		return ans;
    }
};
```