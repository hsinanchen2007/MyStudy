关键在于在两个字符串首部加入'$'字符，优化DP Table初始化以及边际条件的判断。

```
public class Solution {
    public bool IsMatch(string s_1, string p_1) {
        string s = "$" + s_1;
        string p = "$" + p_1;
        int count_s = s.Length;
        int count_p = p.Length;
        
        bool[,] DPTable = new bool[count_s, count_p];
        int i = 0, j = 0;
        
        DPTable[0, 0] = true;

        for (i = 1; i < count_s; i++){
            DPTable[i, 0] = false;
        }
        
        for (j = 1; j < count_p; j++){
            for (i = 0; i < count_s; i++){
                if (p[j] == s[i] || p[j] == '.'){
                    DPTable[i, j] = (i>=1) ? DPTable[i-1, j-1] : false;
                }
                else if (p[j] == '*'){
                    if (s[i] == p[j-1] || p[j-1] == '.'){
                        DPTable[i,j] = (j>=2 ? DPTable[i, j-2] : true) || DPTable[i, j-1] || (i>=1 ? DPTable[i-1, j] : false);
                    }
                    else{
                        DPTable[i,j] = j>=2 ? DPTable[i,j-2] : false;
                    }
                }
                else{
                    DPTable[i,j] = false;
                }
            }
        }
        
        return DPTable[count_s-1, count_p-1];
    }
}
```
