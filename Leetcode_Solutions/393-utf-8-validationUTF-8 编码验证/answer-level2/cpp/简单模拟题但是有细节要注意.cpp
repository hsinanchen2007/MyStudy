```c++
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size(),cnt=0,start = 0;
        while(start<n){
            cnt=0;
            for(int i=7;i>=0;--i){      //判断是几个字节utf8编码
                if(data[start] & 1<<i)cnt++;
                else break;
            }
            if(cnt == 1 | cnt>4 | cnt>n-start)return false;   //一个字节utf8编码的开头是0 超过4个字节的utf8编码 如果不够表示这个utf8编码都返回0;
            for(int i=start+1;i<start+cnt;++i){
                if(!(data[i] & 1<<7) | (data[i] & 1<<6))return false;   //判断是否是10开头
            }
            if(!cnt){
                if(data[start] & 1<<7)return false;     //如果是1个字节的编码检查最高为是否为0
                start+=1;
            }else start += cnt;
        }
        return true;
    }
};
```