***Talk is cheap. Show me the code.***
```
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
    	backtrack(S, 0);
    	return result;
    }

    void backtrack(string S, int round) {
    	if (round == S.size()) {
    		result.push_back(S);
    		return;
    	}
    	if (islower(S[round])) {
    		backtrack(S, round+1);
    		S[round] = toupper(S[round]);
    		backtrack(S, round+1);
    	} else if (isupper(S[round])) {
    		backtrack(S, round+1);
    		S[round] = tolower(S[round]);
    		backtrack(S, round+1);
    	} else {
    		backtrack(S, round+1);    		
    	}
    }

private:
	vector<string> result;
};

```
执行用时还行，内存消耗也就那样了，回溯模板，刷就对了。