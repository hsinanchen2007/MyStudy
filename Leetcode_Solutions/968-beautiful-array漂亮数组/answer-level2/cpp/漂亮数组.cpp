借鉴评论中的思想
起始数组{1}
每次循环，当前数组加上*从大到小2的幂次*，将满足题目条件(小于等于N)的数字加入数组中
最终得到数组即为满足题目条件数组
```
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> vec;
        vec.push_back(1);
        int num=512,len,i;
        while(1+num>N) num>>=1;
        while(num>0){
            len=vec.size();
            for(i=0;i<len;i++){
                if(vec[i]+num<=N) vec.push_back(vec[i]+num);
            }
            num>>=1;
        }
        return vec;
    }
};
```
