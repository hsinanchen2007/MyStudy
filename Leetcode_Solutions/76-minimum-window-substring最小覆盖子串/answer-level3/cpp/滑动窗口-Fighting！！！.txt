通过观察可知：
可定义两个辅助变量，用于控制窗口，定量判断，窗口内的元素是否满足条件即可。
```
class Solution {
public:
    string minWindow(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        if (lent == 0)return "";
        int a[100]={0};
        int b[100]={0};
        for(int i=0;i<lent;i++){
            b[t[i]-'A']++;
        }
        int r=0,l=-1;
        int start=0;
        int res=lens+1;
        for(int i=0;i<lens;i++){
            a[s[i]-'A']++;
            while(judge(a, b)) {
                if(i-start+1 < res) {
                    res = i-start+1;
                    r = start;
                    l = i;
                }
                a[s[start]-'A']--;
                start++;
            }
        }
        string result = "";
        for(int i=r;i<=l;i++)result+=s[i];
        return result;
    }
    bool judge(int *a, int *b) {
        for(int i=0;i<100;i++){
            if(a[i] < b[i])return false;
        }
        return true;
    }
};
```


经过简单的思考得到了上述代码：
提交发现仅仅击败了16%的代码，说明存在较大的优化空间。

judge（判断窗口内元素是否满足情况可优化掉）

如何优化？
可以记录T中需要的字符，用个桶排的原理进行边界处理。
（这里使用数组的时间复杂度，远远优于map映射得到的结果）

得到新的一版代码
```
class Solution {
public:
    string minWindow(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        if (lent == 0)return "";
        int a[100]={0};
        int b[100]={0};
        for(int i=0;i<lent;i++){
            b[t[i]-'A']++;
        }
        int totle = 0;
        for(int i=0;i<100;i++){
            if(b[i] > 0)totle ++,a[i]++;
        }
        int r=0,l=-1;
        int start=0;
        int res=lens+1;
        for(int i=0;i<lens;i++){
            if(a[s[i]-'A']) {
                b[s[i]-'A']--;
                if(b[s[i]-'A'] == 0){
                    totle --;
                }
                while (totle <= 0) {
                    if(res > i-start+1){
                        res= i-start+1;
                        l=start;
                        r=i;
                    }
                    if(a[s[start]-'A']) {
                        b[s[start]-'A']++;
                        if(b[s[start]-'A'] == 1){
                            totle ++;
                        }
                    }
                    start++;
                }
            }
        }
        //cout << l << " " << r << endl;
        if (l < 0) {
            return "";
        }
        return s.substr(l, r-l+1);;
    }
};
```
