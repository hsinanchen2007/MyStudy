### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int ans=0;
    long long low_num,high_num;
    int len,count=0;

    //对于很长的字符串的比较
    //小于:-1,等于:0,大于:1
    int compare(string num,string h_or_l){
        if(num.size()<h_or_l.size()) return -1;
        else if(num.size()>h_or_l.size()) return 1;
        else{
            for(int i=0;i<num.size();i++){
                if(num[i]<h_or_l[i]) return -1;
                else if(num[i]>h_or_l[i]) return 1;
            }
            //相等的情况
            return 0;
        }
    }
    
    int strobogrammaticInRange(string low, string high) {
        low_num=atoi((char*)(low).data());
        high_num=atoi((char*)(high).data());
        int len1=low.size();
        int len2=high.size();
        
        if(len1==len2){
            len=len1;
            dfs(len1,"","",low,high);
        }
        else{
            for(int k=len1;k<=len2;k++){
                len=k;
                dfs(k,"","",low,high);
            }
        }
        return count;
    }

    void dfs(int n,string l,string r,string low,string high){//n代表还没填充的空位的数量,l代表左边的串,r代表右边的串
        if(n==0){
            //左右拼凑起来并且加入vector
            if(compare(l+r,low)>=0&&compare(l+r,high)<=0){count++;}
            return;
        }
        else if(n==1){
            string s;
            s=l+'0'+r;
            if(compare(s,low)>=0&&compare(s,high)<=0){count++;}
            s=l+'1'+r;
            if(compare(s,low)>=0&&compare(s,high)<=0){count++;}
            s=l+'8'+r;
            if(compare(s,low)>=0&&compare(s,high)<=0){count++;}
            return;
        }
        dfs(n-2,l+'6','9'+r,low,high);
        dfs(n-2,l+'9','6'+r,low,high);
        if(n!=len) dfs(n-2,l+'0','0'+r,low,high);
        dfs(n-2,l+'1','1'+r,low,high);
        dfs(n-2,l+'8','8'+r,low,high);
    }
};
```