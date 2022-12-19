参考了跟自己思路类似的解法，没有想到可以逆序单词，好方法
```
class Solution {
public:
static bool cmp(string s1,string s2){
      int N1 = s1.length();
    int N2 = s2.length();
    for (int i = 0; i < min(N1, N2); i++) {
        char c1 = s1[N1-1-i];
        char c2 = s2[N2-1-i];
        if (c1 != c2) {
            return c1 < c2;
        }
    }
    return N1 < N2;

}
    int minimumLengthEncoding(vector<string>& words) {
        int s = words.size();
        int count = 0;
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<s;i++) {
            int sa=words[i].size();
               
                if(i+1<s && words[i+1].substr((words[i+1].size()>sa?words[i+1].size()-sa:sa-words[i+1].size())) == words[i]){
             
    
                }else{
                    count += (sa+1);
                }
          
        }
      
        return count;

    }
};
```
