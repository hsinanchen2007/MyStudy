![QQ截图20191125195001.png](https://pic.leetcode-cn.com/5cb8c91647a60cd2225436134e9bb44c2ac820463d771f90af99ddec72dce178-QQ%E6%88%AA%E5%9B%BE20191125195001.png)

只算距离最近的三个回文数，看哪个距离近也就是差的绝对值小。
例如1234，算的就是1221 1331 1111三个，也就是最中间的数字不变，最中间的数字加一和最中间的数字减一，三种情况。
最麻烦的是数字长度变化时，例如10002，算10001  9999 和 10101
还能精炼一下 懒得写了凑活看吧 

```
class Solution {
public:
    long long converttolong(string &n){
        long long l_src=0;
        int N = n.size();
        for(int i=0;i<N;++i){
            l_src += (n[i] - '0') * pow(10,N-i-1);
        }
        return l_src;
    }
    string nearestPalindromic(string n) {
 
        long long l_src = converttolong(n);
        if(l_src == 1)
            return "0";
        if(l_src == 0)
            return "-1";
    
        int N = n.size();
        int middle = (N+1)/2-1;
        string str1 = n,str2 = n;
        int begin=0,end = N-1;
        while(begin <= end){
            n[end--] = n[begin++];
        }
        long long dis1 = l_src - converttolong(n);
        str1[middle]++;
        while(str1[middle] == ('9'+1)){
            str1[middle] = '0';
            if(middle > 0)
                str1[middle-1]++;
            else{
                str1.insert(0,"1");
                break;
            }
            middle--;
        }

        begin=0;end = str1.size()-1;
        while(begin <= end){
            str1[end--] = str1[begin++];
        }
        long long dis2 = abs(l_src - converttolong(str1));
        middle = (N+1)/2-1;
        str2[middle]--;
        while(str2[middle] == ('0'-1) || (str2[0] == '0')){
            str2[middle] = '9';
            if(middle > 0)
                str2[middle-1]--;
            else{
                str2.erase(str2.begin());
                for(int i=0;i<str2.size();++i)
                    str2[i] = '9';
                break;
            }
            middle--;
        }

        begin=0;end = str2.size()-1;
        while(begin <= end){
            str2[end--] = str2[begin++];
        }
        long long dis3 = abs(l_src - converttolong(str2));
        if(dis1 == 0)
            return dis2 >= dis3?str2:str1;
        else if(dis1 > 0)
            return abs(dis1) > dis2?str1:n;
        else 
            return abs(dis1) >= dis3?str2:n;
    }
};

```
