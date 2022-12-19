## 改进版：不反转，不补零，直接加！
```
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1, c=0, sum=0;
        string ans;
        while(i>=0 || j>=0){
            if(i<0) sum = b[j--] - '0' + c;
            else if(j<0) sum = a[i--] - '0' + c;
            else sum = a[i--] - '0' + b[j--] - '0' + c;
            if(sum > 1){
                ans += (char)(sum-2+'0');
                c = 1;
            }
            else{
                ans += (char)(sum+'0');
                c = 0;
            }
        }
        if(c==1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```


## 反转数组，求和后，再反转回来
**1. 反转两个数组
2. 较短的那个末尾补零对齐
3. 从左到右相加
4. 处理可能有的进位
5. 反转回来**
```
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        //1. 反转两个数组
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int len_a = a.size(), len_b = b.size();
        //2. 较短的那个末尾补零对齐
        while(len_a > len_b){
            b.push_back('0');
            len_b++;
        } 
        while(len_b > len_a){
            a.push_back('0');
            len_a++;
        }
        //3. 从左到右相加
        int sum=0, c=0;
        for(int i=0; i<len_a; i++){
            sum = a[i]+b[i]-'0'+c;
            if(sum > 1){
                ans += (char)(sum-2);
                c = 1;
            }
            else{
                ans += (char)sum;
                c = 0;
            }
        }
        //4. 处理可能有的进位
        if(c==1) ans += '1';
        //5. 反转回来
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```