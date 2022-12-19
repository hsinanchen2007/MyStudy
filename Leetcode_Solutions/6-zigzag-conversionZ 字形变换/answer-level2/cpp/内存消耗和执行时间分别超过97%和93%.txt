最上面一行的字母和最下面一行的字母间隔相同，均为`2 * (numRows - 1)`，并且我们将这个变量设为`base`。
而中间的几行字母，每三个相邻字母之间的间隔之和均为`base`，所以只要我们分析出它们之间的间隔大小和行数之间的关系，就能把它们分别挑选出来。每行第一个间隔为`2 * (numRows - (i + 1))`。
class Solution {
public:
    string convert(string s, int numRows) {
        int i;int k;
        int len = s.size();
        if(len <= numRows||numRows == 1){
            return s;
        }
        string res = "";
        int base = 2 * (numRows - 1);
        int base_0;
        for(i = 0;i < numRows;i++){
            k = i;
            base_0 = 2 * (numRows - (i + 1));
            while(k < len){
                res += s[k];
                if(k % (numRows - 1) == 0){
                    k += 2 * (numRows - 1);
                }
                else{
                    k += base_0;
                    base_0 = base - base_0;
                }
            }
        }
        return res;
    }
};