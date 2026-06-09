方法一 根据位运算
```
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1,index=0;
        string res="";
        for(;i>=0&&j>=0;i--,j--){
            if((a[i]-'0')&&(b[j]-'0')&&index) res +="1";
            else if(!(a[i]-'0')&&!(b[j]-'0')&&!index) res +="0";
            else if((a[i]!=b[j])!=index) res +="1",index=0; 
            else res +="0",index=1;
        }
        if(index){
            for(;i>=0;i--){
                if((a[i]-'0')&&index) res +="0";
                else if((a[i]-'0')^index)  res +="1",index=0;
                else res +="0";
            }
            for(;j>=0;j--){
                if((b[j]-'0')&&index) res +="0";
                else if((b[j]-'0')^index)  res +="1",index=0;
                else res +="0";
            }
            if(index) res +="1";
        }
        else{
            for(;i>=0;i--) res +=a[i];
            for(;j>=0;j--) res +=b[j];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```
方法二
```
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1,index=0;
        string res="";
        for(;i>=0&&j>=0;i--,j--){
            res +=to_string((a[i]-'0'+ b[j]-'0'+index)%2);
            index=(a[i]-'0'+ b[j]-'0'+index)/2;
        }
        if(index){
            for(;i>=0;i--){
                res +=to_string((a[i]-'0'+index)%2);
                index=(a[i]-'0'+index)/2;
            }
            for(;j>=0;j--){
                res +=to_string((b[j]-'0'+index)%2);
                index=(b[j]-'0'+index)/2;
            }
            if(index) res +="1";
        }
        else{
            for(;i>=0;i--) res +=a[i];
            for(;j>=0;j--) res +=b[j];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
```
方法三、补零
```
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1,sum,index = 0;
        string res="";
        for(;i >= 0 || j >= 0; i--, j--) {
            sum = index;
            sum += i >= 0 ? a[i] - '0' : 0;
            sum += j >= 0 ? b[j] - '0' : 0;
            res +=to_string(sum % 2);
            index = sum / 2;
        }
        res += index == 1 ? "1" : "";
        reverse(res.begin(),res.end());
        return res;
    }
};
```
