`我们用两个HashSet来记录验证过的单词，为啥要用两个呢？因为验证的结果有两种，要么通过，要么失败，我们要分别存在两个HashSet中，这样再遇到每种情况的单词时，我们就知道要不要结果增1了。如果单词没有验证过的话，那么我们就用双指针的方法进行验证，然后根据结果的不同，存到相应的HashSet中去---转自阳神的博客`
```
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        if(S.empty()) return 0;
        unordered_set<string> pass, fail;
        int res = 0;
        for(string word:words) {
            if(pass.count(word) || fail.count(word)) {
                if(pass.count(word)) res++;
                continue;
            }
            int i = 0, j = 0;
            while(i<S.size() && j<word.size()) {
                if(S[i] == word[j]) j++;
                i++;
            }
            if(j == word.size()) {
                res++;
                pass.insert(word);
            }
            else fail.insert(word);
        }
        return res;
    }
};
```
